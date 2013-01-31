#ifndef QLED_H
#define QLED_H

#include <Qt>
#include <QWidget>
// #include <QtDesigner/QDesignerExportWidget>


class QColor;

// class QDESIGNER_WIDGET_EXPORT QLed : public QWidget
class QLed : public QWidget
{
 Q_OBJECT
	//Q_PROPERTY(bool value READ value WRITE setValue);
	//Q_PROPERTY(QColor color READ color WRITE setColor);

public: 
    QLed(QWidget *parent = 0);
    bool value() const { return m_value; }
    QColor color() const { return m_color; }
    
public slots:
	void setValue(bool);
	void setColor(QColor);
	void toggleValue();

protected:
    bool m_value;
    QColor m_color;
    void paintEvent(QPaintEvent *event);

};

#endif
