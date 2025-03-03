#ifndef CURTAINWIDGET_H
#define CURTAINWIDGET_H

#include <QWidget>

class CurtainWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CurtainWidget(QWidget *parent = nullptr);

    void setOpenness(int value);

    ~CurtainWidget();

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    int openness = 50;
    QColor curtainColor = QColor(70, 130, 180);
signals:

public slots:
};

#endif // CURTAINWIDGET_H
