#ifndef SIGNUP_H
#define SIGNUP_H

#include <QWidget>

namespace Ui {
class SignUp;
}

class SignUp : public QWidget
{
	Q_OBJECT

public:
	enum TypeRegistration { Passenger, Admin };

    explicit SignUp(TypeRegistration typeReg, QWidget *parent = nullptr);
    ~SignUp();

private:
    Ui::SignUp *mUi;
	TypeRegistration m_typeReg;
	bool isLoginExists(const QString &login);

signals:
	void openAuthorization();

private slots:
	void on_buttonCreate_clicked();
};

#endif // SIGNUP_H
