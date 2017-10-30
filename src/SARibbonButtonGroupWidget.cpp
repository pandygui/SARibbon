#include "SARibbonButtonGroupWidget.h"
#include <QHBoxLayout>
#include <QDebug>
#include <QMargins>
#include <QChildEvent>
class SARibbonButtonGroupWidgetPrivate
{
public:
    SARibbonButtonGroupWidget* Parent;
    SARibbonButtonGroupWidgetPrivate(SARibbonButtonGroupWidget* p)
    {
        Parent = p;
    }
    void init()
    {
        QHBoxLayout *layout = new QHBoxLayout;
        layout->setMargin(0);
        layout->setSpacing(0);
        Parent->setLayout(layout);
    }
};

SARibbonButtonGroupWidget::SARibbonButtonGroupWidget(QWidget *parent)
    :QFrame(parent)
    ,m_d(new SARibbonButtonGroupWidgetPrivate(this))
{
    m_d->init();
}

SARibbonButtonGroupWidget::~SARibbonButtonGroupWidget()
{
    delete m_d;
}

void SARibbonButtonGroupWidget::addButton(QAbstractButton *btn)
{
    btn->setParent(this);
    layout()->addWidget(btn);
    layout()->setAlignment(btn,Qt::AlignCenter);
}

SARibbonToolButton *SARibbonButtonGroupWidget::addButton(QAction *action)
{
    SARibbonToolButton* btn = new SARibbonToolButton(action,this);
    btn->setToolButtonStyle(Qt::ToolButtonIconOnly);
    btn->setFixedSize(26,26);
    layout()->addWidget(btn);
    layout()->setAlignment(btn,Qt::AlignCenter);
    return btn;
}

QSize SARibbonButtonGroupWidget::sizeHint() const
{
    return layout()->sizeHint();
}

QSize SARibbonButtonGroupWidget::minimumSizeHint() const
{
    return layout()->minimumSize();
}
