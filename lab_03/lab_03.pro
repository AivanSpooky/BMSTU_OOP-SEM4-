QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++20

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += $$PWD/objects
INCLUDEPATH += $$PWD/objects/invisibleobject
INCLUDEPATH += $$PWD/objects/visibleobject
INCLUDEPATH += $$PWD/objects/visibleobject/carcassmodel

INCLUDEPATH += $$PWD/scene

INCLUDEPATH += $$PWD/historyholder
INCLUDEPATH += $$PWD/historyholder/command

INCLUDEPATH += $$PWD/matrix
INCLUDEPATH += $$PWD/matrix/errors
INCLUDEPATH += $$PWD/matrix/iterator
INCLUDEPATH += $$PWD/matrix/matrix

INCLUDEPATH += $$PWD/facade

INCLUDEPATH += $$PWD/load/builders
INCLUDEPATH += $$PWD/load/builders/camera
INCLUDEPATH += $$PWD/load/builders/model
INCLUDEPATH += $$PWD/load/builders/scene
INCLUDEPATH += $$PWD/load/directors
INCLUDEPATH += $$PWD/load/directors/camera
INCLUDEPATH += $$PWD/load/directors/model
INCLUDEPATH += $$PWD/load/directors/readers
INCLUDEPATH += $$PWD/load/directors/scene
INCLUDEPATH += $$PWD/load/moderators
INCLUDEPATH += $$PWD/load/moderators/camera
INCLUDEPATH += $$PWD/load/moderators/creators
INCLUDEPATH += $$PWD/load/moderators/model
INCLUDEPATH += $$PWD/load/moderators/scene

INCLUDEPATH += $$PWD/managers
INCLUDEPATH += $$PWD/managers/creators
INCLUDEPATH += $$PWD/managers/draw
INCLUDEPATH += $$PWD/managers/load
INCLUDEPATH += $$PWD/managers/scene
INCLUDEPATH += $$PWD/managers/transform
INCLUDEPATH += $$PWD/managers/history

INCLUDEPATH += $$PWD/transform

INCLUDEPATH += $$PWD/exceptions
INCLUDEPATH += $$PWD/drawer
INCLUDEPATH += $$PWD/commands
INCLUDEPATH += $$PWD/adapters
INCLUDEPATH += $$PWD/adapters/composite
INCLUDEPATH += $$PWD/adapters/model

SOURCES += \
    commands/undocommand.cpp \
    historyholder/command/commandhistorycarrytaker.cpp \
    load/builders/camera/basecamerabuilder.cpp \
    load/builders/model/basemodelbuilder.cpp \
    load/builders/scene/basescenebuilder.cpp \
    main.cpp \
    mainwindow.cpp \
    managers/creators/historymanagercreator.cpp \
    matrix/matrix/matrix_base.cpp \
    objects/composite.cpp \
    objects/object.cpp \
    objects/invisibleobject/camera.cpp \
    objects/visibleobject/basemodel.cpp \
    objects/visibleobject/carcassmodel/carcassmodel.cpp \
    objects/visibleobject/carcassmodel/link.cpp \
    objects/visibleobject/carcassmodel/matrixmodelstructure.cpp \
    objects/visibleobject/carcassmodel/modelstructure.cpp \
    objects/visibleobject/carcassmodel/vertex.cpp \
    scene/scene.cpp \
    load/builders/model/modelbuilder.cpp \
    load/builders/scene/scenebuilder.cpp \
    load/builders/camera/camerabuilder.cpp \
    load/directors/camera/filecamerabuilddirector.cpp \
    load/directors/model/filemodelbuilddirector.cpp \
    load/directors/readers/basecarcassmodelreader.cpp \
    load/directors/readers/filecarcassmodelreader.cpp \
    load/directors/scene/filescenebuilddirector.cpp \
    load/moderators/baseloadmoderator.cpp \
    load/moderators/camera/cameraloadmoderator.cpp \
    load/moderators/creators/cameraloadmoderatorcreator.cpp \
    load/moderators/creators/modelloadmoderatorcreator.cpp \
    load/moderators/creators/sceneloadmoderatorcreator.cpp \
    load/moderators/model/modelloadmoderator.cpp \
    load/moderators/scene/sceneloadmoderator.cpp \
    managers/creators/drawmanagercreator.cpp \
    managers/creators/loadmanagercreator.cpp \
    managers/creators/scenemanagercreator.cpp \
    managers/creators/transformmanagercreator.cpp \
    managers/draw/drawmanager.cpp \
    managers/load/loadmanager.cpp \
    managers/scene/scenemanager.cpp \
    managers/transform/transformmanager.cpp \
    managers/history/historymanager.cpp \
    adapters/composite/drawcompositeadapter.cpp \
    adapters/model/drawcarcassmodeladapter.cpp \
    commands/basecommand.cpp \
    commands/cameracommand.cpp \
    commands/modelcommand.cpp \
    commands/modelscommand.cpp \
    commands/scenecommand.cpp \
    drawer/qtdrawer.cpp \
    drawer/qtdrawerfactory.cpp \
    facade/facade.cpp \
    transform/transformer.cpp

HEADERS += \
    commands/undocommand.h \
    historyholder/basehistorycarrytaker.h \
    historyholder/command/commandhistorycarrytaker.h \
    load/directors/readers/carcassmodelreaderfactory.h \
    mainwindow.h \
    managers/creators/historymanagercreator.h \
    matrix/matrix/matrix.h \
    matrix/matrix/matrix.hpp \
    matrix/matrix/matrix_base.hpp \
    matrix/iterator/const_matrix_iterator.h \
    matrix/iterator/const_matrix_iterator.hpp \
    matrix/iterator/matrix_iterator.h \
    matrix/iterator/matrix_iterator.hpp \
    matrix/errors/errors.hpp \
    objects \
    objects/composite.h \
    objects/object.h \
    objects/invisibleobject/camera.h \
    objects/invisibleobject/invisibleobject.h \
    objects/visibleobject/basemodel.h \
    objects/visibleobject/carcassmodel/basemodelstructure.h \
    objects/visibleobject/carcassmodel/matrixmodelstructure.h \
    objects/visibleobject/visibleobject.h \
    objects/visibleobject/carcassmodel/carcassmodel.h \
    objects/visibleobject/carcassmodel/link.h \
    objects/visibleobject/carcassmodel/modelstructure.h \
    objects/visibleobject/carcassmodel/vertex.h \
    scene/scene.h \
    load/builders/basebuilder.h \
    load/builders/model/basemodelbuilder.h \
    load/builders/model/modelbuilder.h \
    load/builders/scene/basescenebuilder.h \
    load/builders/scene/scenebuilder.h \
    load/builders/camera/basecamerabuilder.h \
    load/builders/camera/camerabuilder.h \
    load/directors/basedirector.h \
    load/directors/camera/basecamerabuilddirector.h \
    load/directors/camera/filecamerabuilddirector.h \
    load/directors/model/basemodelbuilddirector.h \
    load/directors/model/filemodelbuilddirector.h \
    load/directors/readers/basecarcassmodelreader.h \
    load/directors/readers/filecarcassmodelreader.h \
    load/directors/scene/basescenebuilddirector.h \
    load/directors/scene/filescenebuilddirector.h \
    load/moderators/baseloadmoderator.h \
    load/moderators/camera/cameraloadmoderator.h \
    load/moderators/creators/cameraloadmoderatorcreator.h \
    load/moderators/creators/modelloadmoderatorcreator.h \
    load/moderators/creators/sceneloadmoderatorcreator.h \
    load/moderators/creators/moderatorsolution.h \
    load/moderators/model/modelloadmoderator.h \
    load/moderators/scene/sceneloadmoderator.h \
    managers/basemanager.h \
    managers/creators/drawmanagercreator.h \
    managers/creators/loadmanagercreator.h \
    managers/creators/scenemanagercreator.h \
    managers/creators/transformmanagercreator.h \
    managers/creators/managersolution.h \
    managers/draw/drawmanager.h \
    managers/load/loadmanager.h \
    managers/scene/scenemanager.h \
    managers/transform/transformmanager.h \
    managers/history/historymanager.h \
    adapters/baseadapter.h \
    adapters/composite/compositeadapter.h \
    adapters/composite/drawcompositeadapter.h \
    adapters/model/modeladapter.h \
    adapters/model/drawcarcassmodeladapter.h \
    commands/basecommand.h \
    commands/cameracommand.h \
    commands/modelcommand.h \
    commands/modelscommand.h \
    commands/scenecommand.h \
    drawer/abstractdrawerfactory.h \
    drawer/basedrawer.h \
    drawer/drawerfactorysolution.h \
    drawer/abstractdrawerfactory.hpp \
    drawer/qtdrawer.h \
    drawer/qtdrawerfactory.h \
    exceptions/exceptions.h \
    facade/facade.h \
    transform/transformer.h



FORMS += \
    mainwindow.ui

DISTFILES += \
    data/cone.txt \
    data/cube.txt \
    data/tesseract.txt \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
