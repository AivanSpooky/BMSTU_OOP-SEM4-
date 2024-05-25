#include "basemodelbuilder.h"

BaseModelBuilder::BaseModelBuilder(std::shared_ptr<FileCarcassModelReader> &reader)
    : _reader(reader) {}
