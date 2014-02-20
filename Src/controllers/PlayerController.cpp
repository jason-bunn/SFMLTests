#include <controllers/PlayerController.hpp>
#include <SFML/Window/Keyboard.hpp>

PlayerController::PlayerController(int id, int eID, tgd::System& mSystem)
: Controller(id, eID)
, mMoveVector()
, mSprite(nullptr)
, mMapPtr(mSystem.mMapPtr)
, mColFlag(-1)
, moveDir(Down)
{
    retrieveProperties(eID, mSystem);
    mMoveVector = sf::Vector2f(0,0);

    //setup collision points
    collisionPoints[0] = sf::Vector2f(-25, -32); //top left
    collisionPoints[1] = sf::Vector2f( 25, -32); //top right
    collisionPoints[2] = sf::Vector2f(-25,  32); //bottom left
    collisionPoints[3] = sf::Vector2f( 25,  32); //bottom right
    collisionPoints[4] = sf::Vector2f( 32, -25); //right top
    collisionPoints[5] = sf::Vector2f( 32,  25); //right bottom
    collisionPoints[6] = sf::Vector2f( -32, -25); //left top
    collisionPoints[7] = sf::Vector2f( -32,  25); //left bottom
}

PlayerController::~PlayerController()
{

}

void PlayerController::update(sf::Time dt)
{

    handleRealtimeInput();

    mColFlag = checkCollisions();

    //std::cout << "Col Flag: " << mColFlag << std::endl;

    setVelocity(mMoveVector, dt);
}

void PlayerController::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

}

void PlayerController::handleRealtimeInput()
{
    mMoveVector = sf::Vector2f(0,0);



    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        if(mColFlag[0] != 1 && mColFlag[1] != 1)
        {
            mMoveVector.y += -200;
        }

        moveDir = Up;


    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        if(mColFlag[2] != 1 && mColFlag[3] != 1)
        {
            mMoveVector.y += 200;
        }
        moveDir = Down;


    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        if(mColFlag[4] != 1 && mColFlag[5] !=1 )
        {

            mMoveVector.x += 200;
        }
        moveDir = Right;


    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        if(mColFlag[6] != 1 && mColFlag[7] != 1)
        {
            mMoveVector.x += -200;
        }
        moveDir = Left;


    }

}

std::bitset<8> PlayerController::checkCollisions()
{
    std::bitset<8> bitMask(std::string("0000"));
    //this currently only checks collisions with the map
    std::vector<tmx::MapObject*> objects = mMapPtr->QueryQuadTree(mSprite->getGlobalBounds());
    //std::cout << "Objects on screen: " << objects.size() << std::endl;
    for(int i = 0; i<objects.size(); i++)
    {
        for(int j = 0; j<8; j++)
        {
            if(objects[i]->Contains(mSprite->getPosition() + collisionPoints[j]))
            {
                //std::cout<<"Collision Detected" << std::endl;
                bitMask[j] = 1;

            }
        }
    }

    return bitMask;
}



void PlayerController::retrieveProperties(int eID, tgd::System& system)
{
    std::shared_ptr<tgd::Entity> tempEnt;
    tempEnt = system.fetchEntity(eID);
    auto sprPtr = std::dynamic_pointer_cast<tgd::Property<sf::Sprite>>(tempEnt->accessProperty(Properties::Visible));
    mSprite = sprPtr->getValue();
}

int PlayerController::getID()
{
    return Controller::getID();
}

int PlayerController::getEntityID()
{
    return Controller::getEntityID();
}

void PlayerController::setVelocity(sf::Vector2f moveVector, sf::Time dt)
{

    mSprite->move(moveVector * dt.asSeconds());

}

std::bitset<32> PlayerController::getRequirements()
{

    return (Properties::PC | Properties::Visible | Properties::Velocity | Properties::Position);

}
