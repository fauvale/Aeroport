#include "addrace.h"
#include "ui_dialog_addrace.h"

#include "config.h"
#include "plane.h"
#include "controlpassengers.h"

AddRace::AddRace(Plane *plane, const QList<Plane> &listPlanes, Type type, QWidget *parent) :
    QDialog(parent),
    mUi(new Ui::AddRace),
    m_plane(plane),
    m_listPlanes(listPlanes)
{
    mUi->setupUi(this);

    m_startNumberPlane = plane->number();

    if (type == Edit) {
        mUi->mainLabel->setText("Редактирование рейса");
        mUi->edit_number->setText(m_plane->number());
        mUi->edit_departure->setText(m_plane->departure());
        mUi->edit_arrival->setText(m_plane->departure());
        mUi->edit_mark->setText(m_plane->mark());
        mUi->edit_countSeats->setValue(m_plane->countSeats());
    }
    else {
        mUi->mainLabel->setText("Добавление рейса");
    }

    m_dialogControlPassengers = new ControlPassengers(plane->listPassengers(), this);
    m_dialogControlPassengers->setWindowTitle(Config::nameApplication);
}

AddRace::~AddRace()
{
    delete mUi;
    delete m_dialogControlPassengers;
}

void AddRace::accept()
{
    mUi->labelError->clear();

    QString number = mUi->edit_number->text();
    QString departure = mUi->edit_departure->text();
    QString arrival = mUi->edit_arrival->text();
    QString mark = mUi->edit_mark->text();
    int countSeats = mUi->edit_countSeats->value();
    int countFreeSeats = countSeats;
    if (number.isEmpty() ||
        departure.isEmpty() ||
        arrival.isEmpty() ||
        mark.isEmpty() ||
        countSeats == 0) {
        mUi->labelError->setText("Ошибка: заполните все поля!");
    } else {
        m_plane->setData(number, departure, arrival, mark, countSeats, countFreeSeats, m_dialogControlPassengers->listPassengers());
        QDialog::accept();
    }
}

void AddRace::on_buttonEditPassengers_clicked()
{
    m_dialogControlPassengers->exec();
}
