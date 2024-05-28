#ifndef COMPOSITE_H
#define COMPOSITE_H

#include "errors.hpp"
#include "object.h"

class Composite : public Object
{
    friend class DrawCompositeAdapter;

public:
    Composite() = default;
    explicit Composite(std::shared_ptr<Object> &element);
    explicit Composite(const std::vector<std::shared_ptr<Object>> &vector);

    bool add(const std::shared_ptr<Object> &element) override;
    bool remove(const Iterator &iter) override;
    void updateCenter() override;

    virtual bool isVisible() override;
    virtual bool isComposite() override;

    virtual Vertex getCenter() const override;
    virtual void transform(Transformer &mtr, const Vertex &center) override;

    Iterator begin() override;
    Iterator end() override;

protected:
    void moveElemsToOrigin(const Vertex &center) override;
    void moveElemsToCenter(const Vertex &center) override;
    void transformElems(Transformer &mtr) override;

private:
    Vertex _center;
    std::vector<std::shared_ptr<Object>> _elements;
};

#endif //COMPOSITE_H
