/*
 * Warning:
 * ----------------------------------------------------------
 * Uncommented, cancer inducing code ahead.
 * Read at your own risk.
 *
 *
 */

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <thread>
#include <chrono>


static unsigned int HEIGHT = 0;
static unsigned int WIDTH = 0;


enum Direction {
    up = 0,
    down = 1,
    left = 3,
    right = 4
};

struct Position {
    float x;
    float y;
    Position(float paramX, float paramY){
        this -> x = paramX;
        this -> y = paramY;
    }
    Position(){
        this -> x = 0;
        this -> y = 0;
    }
};

class Entity {
    protected:
    
    unsigned int height, width;
    Position pos;
    sf::Sprite sprite;
    
    public:
    
    sf::Sprite getSprite(){
        return this -> sprite;
    }
};

class Food : public Entity {
    private:
    
    sf::Texture texture;
    
    public:
    
    Food(){
        this -> height = 30;
        this -> width = 30;
        this -> texture.loadFromFile("Resources/blankTexture.jpg", sf::IntRect(0, 0, this -> width, this -> height));
        this -> sprite.setTexture(this -> texture);
        this -> sprite.setColor(sf::Color(216, 54, 58));
        this -> pos.x = rand() % (WIDTH - this -> width * 2) + this -> width;
        this -> pos.y = rand() % (HEIGHT - this -> height * 2) + this -> height;
        this -> sprite.setPosition(this -> pos.x, this -> pos.y);
    }
    
    void newFood(){
        this -> pos.x = rand() % (WIDTH - this -> width * 2) + this -> width;
        this -> pos.y = rand() % (HEIGHT - this -> height * 2) + this -> height;
        this -> sprite.setPosition(this -> pos.x, this -> pos.y);
    }
    
    Position getPosition(){
        return this -> pos;
    }
};

class SnakePart : Entity {
    
    public:
    
    SnakePart(sf::Texture texture, Position position){
        this -> sprite.setTexture(texture);
        this -> sprite.setColor(sf::Color(254, 212, 67));
        this -> pos = position;
        this -> sprite.setPosition(this -> pos.x, this -> pos.y);
    }
    
    void setPosition(Position position){
        this -> pos.x = position.x;
        this -> pos.y = position.y;
        this -> sprite.setPosition(this -> pos.x, this -> pos.y);
    }
    
    void move(Position position){
        this -> pos.x = position.x;
        this -> pos.y = position.y;
        this -> sprite.setPosition(this -> pos.x, this -> pos.y);
    }
    
    
    sf::Sprite getSprite(){
        return this -> sprite;
    }
    
    Position getPosition(){
        return this -> pos;
    }
};

class Snake : public Entity{
    private:
    
    std::vector<SnakePart> snakeParts;
    sf::Texture texture;
    sf::Sprite sprite;
    Direction dir;
    
    public:
    
    Snake(){
        this -> height = 60;
        this -> width = 60;
        this -> texture.loadFromFile("Resources/blankTexture.jpg", sf::IntRect(0, 0, this -> width, this -> height));
        this -> sprite.setTexture(texture);
        this -> sprite.setColor(sf::Color(254, 212, 67));
        this -> pos = Position::Position(WIDTH / 2, HEIGHT / 2);
        this -> sprite.setPosition(this -> pos.x, this -> pos.y);
    }
    
    void setDirection(Direction direction){
        if (this -> snakeParts.size() && abs(this -> dir - direction) == 1){
            return;
        }
        this -> dir = direction;
    }
    
    void draw(sf::RenderWindow * window){
        window -> draw(this -> sprite);
        for (SnakePart i : this -> snakeParts){
            window -> draw(i.getSprite());
        }
    }
    
    void move(){
        
        for (int i = this -> snakeParts.size() - 1; i >= 0; --i) {
            if (!i){
                this -> snakeParts.at(i).move(this -> pos);
            }
            else {
                this -> snakeParts.at(i).move(this -> snakeParts.at(i - 1).getPosition());
            }
        }
        
        switch (this -> dir) {
            case Direction::up:
                this -> pos.y -= 60;
                break;
            case Direction::down:
                this -> pos.y += 60;
                break;
            case Direction::left:
                this -> pos.x -= 60;
                break;
            case Direction::right:
                this -> pos.x += 60;
                break;
                
            default:
                break;
        }
        if (this -> pos.x < 0){
            this -> pos.x = WIDTH - 60;
        }
        else if (this -> pos.x > WIDTH - 60){
            this -> pos.x = 0;
        }
        if (this -> pos.y < 0){
            this -> pos.y = HEIGHT - 60;
        }
        else if (this -> pos.y > HEIGHT - 60){
            this -> pos.y = 0;
        }
        this -> sprite.setPosition(this -> pos.x, this -> pos.y);
    }
    
    void collisionWithFood(Food * food){
        if (this -> pos.x - food -> getPosition().x > 30 || this -> pos.x - food -> getPosition().x < -60) {
            return;
        }
        if (this -> pos.y - food -> getPosition().y > 30 || this -> pos.y - food -> getPosition().y < -60) {
            return;
        }
        food -> newFood();
        if (!(this -> snakeParts.size())) {
            this -> snakeParts.emplace_back(this -> texture, this -> pos);
        }
        else {
            this -> snakeParts.emplace_back(this -> texture, this -> snakeParts.back().getPosition());
        }
    }
    
    bool collision(){
        for (int i = this -> snakeParts.size() - 1; i > 0; --i){
            if (this -> pos.x == this -> snakeParts.at(i).getPosition().x && this -> pos.y == this -> snakeParts.at(i).getPosition().y) return true;
        }
        return false;
    }
    
};

void gameOver(sf::RenderWindow * window) {
    
    
    
}

int main(int argc, const char* argv[]){
    
    srand(unsigned(time(nullptr)));
    
    const sf::VideoMode vm = sf::VideoMode::getFullscreenModes().at(0);
    
    sf::RenderWindow window(vm, "Snake", sf::Style::Fullscreen);
    window.setFramerateLimit(15);
    window.setVerticalSyncEnabled(true);
    window.setMouseCursorVisible(false);
    HEIGHT = vm.height;
    WIDTH = vm.width;
    
    sf::Texture mapTexture;
    if (!mapTexture.loadFromFile("Resources/blankTexture.jpg")){
        return -1;
    }
    sf::Sprite mapSprite(mapTexture);
    mapSprite.setColor(sf::Color(47, 213, 102));
    
    Food food;
    Snake snake;
    unsigned int counter = 0;
    bool exit = false;
    
    while (!exit && window.isOpen()) {
        
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                switch (event.key.code) {
                    case sf::Keyboard::Escape:
                        window.close();
                        break;
                    case sf::Keyboard::W:
                        snake.setDirection(Direction::up);
                        break;
                    case sf::Keyboard::S:
                        snake.setDirection(Direction::down);
                        break;
                    case sf::Keyboard::D:
                        snake.setDirection(Direction::right);
                        break;
                    case sf::Keyboard::A:
                        snake.setDirection(Direction::left);
                        break;
                    default:
                        break;
                }
                break;
            }
        }
        snake.move();
        snake.collisionWithFood(&food);
        
        if (snake.collision()) exit = true;
        
        window.clear();
        window.draw(mapSprite);
        snake.draw(&window);
        window.draw(food.getSprite());
        window.display();
    }
    
    sf::Font font;
    if (!font.loadFromFile("Resources/Helvetica.otf")) return;
    sf::Text text("GAME OVER", font, 100);
    
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    text.setPosition(sf::Vector2f(WIDTH / 2.0f,HEIGHT / 2.0f));
    
    text.setColor(sf::Color::Black);
    exit = false;
    
    window.clear();
    window.draw(mapSprite);
    snake.draw(&window);
    window.draw(food.getSprite());
    window.draw(text);
    window.display();
    std::this_thread::sleep_for(std::chrono::milliseconds(250));
    
    while (!exit) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                exit = true;
            }
            if (event.type == sf::Event::KeyPressed) {
                exit = true;
            }
        }
        window.clear();
        window.draw(mapSprite);
        snake.draw(&window);
        window.draw(food.getSprite());
        window.draw(text);
        window.display();
    }
    
    if (window.isOpen()) window.close();

    return 0;
}