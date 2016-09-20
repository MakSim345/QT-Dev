#ifndef _BELOWS_ENH_
#define _BELOWS_ENH_

#include <QWidget>
#include <QPainter>
#include <math.h>


class BelowsEnh : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QColor colorBg READ colorBg WRITE setColorBg);
    Q_PROPERTY(QColor colorValue READ colorValue WRITE setColorValue);
    Q_PROPERTY(QColor colorLow READ colorLow WRITE setColorLow);
    Q_PROPERTY(QColor colorHigh READ colorHigh WRITE setColorHigh);
    Q_PROPERTY(double leftValue READ leftValue WRITE setLeftValue);
    Q_PROPERTY(double rightValue READ rightValue WRITE setRightValue);
    Q_PROPERTY(double minValue READ minValue WRITE setMinValue);
    Q_PROPERTY(double maxValue READ maxValue WRITE setMaxValue);
    Q_PROPERTY(int dimValue READ valueDim WRITE setValueDim);

    QColor colorBg() const
    {
        return colBack;
    }
    QColor colorValue() const
    {
        return colValue;
    }
    QColor colorLow() const
    {
        return colLow;
    }
    QColor colorHigh() const
    {
        return colHigh;
    }
    double leftValue() const
    {
        return leftVal;
    }
    double rightValue() const
    {
        return rightVal;
    }
    double minValue() const
    {
        return min;
    }
    double maxValue() const
    {
        return max;
    }
    int valueDim() const
    {
        return dimVal;
    }


public:

    BelowsEnh(QWidget *parent = 0);
    QSize minimumSizeHint() const;
    QSize sizeHint() const;


signals:

    void valueLChanged(double);
    void valueRChanged(double);

public slots:

    void setColorBg(QColor);
    void setColorValue(QColor);
    void setColorHigh(QColor);
    void setColorLow(QColor);
    void setValueDim(int);
    void setLeftValue(double);
    void setRightValue(double);
    void setMinValue(double);
    void setMaxValue(double);
    void setProgrBarValue(int);


protected:

    void paintEvent(QPaintEvent *);
    void paintBorder();
    void paintBar();
    void paintValue();



private:

    double min;
    double max;
    double leftVal;
    double rightVal;
    int dimVal;
    QColor colBack;
    QColor colValue;
    QColor colHigh;
    QColor colLow;


};

#endif
