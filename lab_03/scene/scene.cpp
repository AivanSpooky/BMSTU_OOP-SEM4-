#include <iterator>
#include <algorithm>

#include "scene.h"
#include "composite.h"

#include <QDebug>

Scene::Scene() { }

std::size_t Scene::addObject(const std::shared_ptr<Object> &object)
{
    _objects.push_back(object);

    return object->getId();
}

std::size_t Scene::addCamera(const Vertex &location)
{
    auto camera = std::make_shared<Camera>(Camera(location));
    _objects.push_back(camera);
    _cameras.push_back(--_objects.end());

    return camera->getId();
}

void Scene::deleteObject(Iterator &iter)
{
    if (std::find(_cameras.begin(), _cameras.end(), iter) != _cameras.end())
    {
        _cameras.erase(std::remove(_cameras.begin(), _cameras.end(), iter), _cameras.end());
    }
    _objects.erase(iter);
}

Iterator Scene::getObjectIter(const std::size_t id)
{
    return std::find_if(_objects.begin(), _objects.end(), [id](const std::shared_ptr<Object>& obj) {
        return obj->getId() == id;
    });
}

std::shared_ptr<Object> Scene::getObject(const std::size_t id)
{
    auto iter = getObjectIter(id);
    return (iter != _objects.end()) ? *iter : nullptr;
}

std::shared_ptr<Composite> Scene::getVisibleObjects()
{
    auto visibleObjects = std::make_shared<Composite>();
    for (const auto& obj : _objects)
    {
        if (obj->isVisible())
        {
            visibleObjects->add(obj);
        }
    }
    return visibleObjects;
}

std::shared_ptr<Composite> Scene::getInvisibleObjects()
{
    auto invisibleObjects = std::make_shared<Composite>();
    for (const auto& obj : _objects)
    {
        if (!obj->isVisible())
        {
            invisibleObjects->add(obj);
        }
    }
    return invisibleObjects;
}

Iterator Scene::vbegin()
{
    return _objects.begin();
}

Iterator Scene::vend()
{
    return _objects.end();
}

Iterator Scene::ibegin()
{
    return _objects.begin();
}

Iterator Scene::iend()
{
    return _objects.end();
}
