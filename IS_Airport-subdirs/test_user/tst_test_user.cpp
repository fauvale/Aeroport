#include <QtTest>
#include "user.h"

// add necessary includes here

class test_user : public QObject
{
    Q_OBJECT

public:
    test_user();
    ~test_user();

private slots:
    void test_default_constructor();
    void test_init_constructor();
    void test_set_data();
    void test_get_set();
    void test_get_list_status();
    void test_up_status();
    void test_down_status();
};

test_user::test_user()
{

}

test_user::~test_user()
{

}

void test_user::test_default_constructor()
{
    User u;
    QCOMPARE(u.login(), "");
    QCOMPARE(u.password(), "");
}
void test_user::test_init_constructor()
{
    User u("test1", "test2", User::Status::Admin);
    QCOMPARE(u.login(), "test1");
    QCOMPARE(u.password(), "test2");
    QCOMPARE(u.status(), User::Status::Admin);
}
void test_user::test_set_data()
{
    User u;
    u.setData("test1", "test2", User::Status::Admin);
    QCOMPARE(u.login(), "test1");
    QCOMPARE(u.password(), "test2");
    QCOMPARE(u.status(), User::Status::Admin);
}
void test_user::test_get_set()
{
    User u;
    u.setLogin("test1");
    u.setPassword("test2");
    u.setStatus(User::Status::Admin);
    QCOMPARE(u.login(), "test1");
    QCOMPARE(u.password(), "test2");
    QCOMPARE(u.status(), User::Status::Admin);
}
void test_user::test_get_list_status()
{
    auto list = User::getListStatus();
    QCOMPARE(list[User::Status::Admin], "Администратор");
    QCOMPARE(list[User::Status::Cashier], "Кассир");
    QCOMPARE(list[User::Status::Passenger], "Пассажир");
}
void test_user::test_up_status()
{
    User u("test1", "test2", User::Status::Passenger);
    QCOMPARE(u.status(), User::Status::Passenger);
    QCOMPARE(u.upStatus(), true);
    QCOMPARE(u.status(), User::Status::Cashier);
    QCOMPARE(u.upStatus(), true);
    QCOMPARE(u.status(), User::Status::Admin);
    QCOMPARE(u.upStatus(), false);
}
void test_user::test_down_status()
{
    User u("test1", "test2", User::Status::Admin);
    QCOMPARE(u.status(), User::Status::Admin);
    QCOMPARE(u.downStatus(), true);
    QCOMPARE(u.status(), User::Status::Cashier);
    QCOMPARE(u.downStatus(), true);
    QCOMPARE(u.status(), User::Status::Passenger);
    QCOMPARE(u.downStatus(), false);
}

QTEST_APPLESS_MAIN(test_user)

#include "tst_test_user.moc"
