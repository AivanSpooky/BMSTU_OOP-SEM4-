#include "drawcompositeadapter.h"

void DrawCompositeAdapter::setCamera(std::shared_ptr<Camera> camera)
{
    _camera = camera;
}

void DrawCompositeAdapter::setDrawer(std::shared_ptr<BaseDrawer> drawer)
{
    _drawer = drawer;
}

void DrawCompositeAdapter::request()
{
    if (_adaptee && _camera && _drawer)
    {
        for (auto &elem : _adaptee->_elements)
        {
            if (elem->isComposite())
            {
                auto com_sh_ptr = std::dynamic_pointer_cast<Composite>(elem);
                processElement<DrawCompositeAdapter>(com_sh_ptr);
            }
            else
            {
                auto model_sh_ptr = std::dynamic_pointer_cast<CarcassModel>(elem);
                processElement<DrawCarcassModelAdapter>(model_sh_ptr);
            }
        }
    }
}

template<typename AdapterType, typename AdapteeType>
void DrawCompositeAdapter::processElement(std::shared_ptr<AdapteeType> elem)
{
    auto adapter = std::make_shared<AdapterType>(AdapterType());
    adapter->setAdaptee(elem);
    adapter->setCamera(_camera);
    adapter->setDrawer(_drawer);
    adapter->request();
}
