#ifndef DRAWCOMPOSITEADAPTER_H
#define DRAWCOMPOSITEADAPTER_H

#include "compositeadapter.h"
#include "camera.h"
#include "basedrawer.h"

class DrawCompositeAdapter : public CompositeAdapter
{
public:
    void setCamera(std::shared_ptr<Camera> camera);
    void setDrawer(std::shared_ptr<BaseDrawer> drawer);

    virtual void request() override;

private:
    std::shared_ptr<Camera> _camera;
    std::shared_ptr<BaseDrawer> _drawer;

    template<typename AdapterType, typename AdapteeType>
    void processElement(std::shared_ptr<AdapteeType> elem);
};


#endif // DRAWCOMPOSITEADAPTER_H
