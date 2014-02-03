

template <typename T>
void tgd::System::createEntity()
{
    std::shared_ptr<T> ent(new T(mEntityCount, textureHolder));
    //T entity(mEntityCount);
    //T *entPtr = &entity;
    //registerEntity(entity);
    registerEntity(ent);
    mEntityCount++;
}
template <typename T>
void tgd::System::registerEntity(std::shared_ptr<T> entity)
{
    //at some point you might want to check for empty portions of the list (ie if an entity is destroyed)

    mEntities.insert(std::pair<unsigned int, std::shared_ptr<T>>(mEntityCount, entity));
    checkProperties(entity->getEntityID());

}


