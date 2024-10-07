#include <QApplication>
#include <QWidget>
#include <QTabWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QColorDialog>
#include <QFileDialog>
#include <QColor>
#include <QFontDialog>
#include <QFont>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget *window = new QWidget;
    window->setWindowTitle("Group7");

    QTabWidget *tabWidget = new QTabWidget;

    // Leader tab
    QWidget *tab1 = new QWidget();
    QVBoxLayout *layout1 = new QVBoxLayout();
    layout1->setSpacing(1);
    QLabel *label1 = new QLabel("Leader    50915122 廖御証");
    QLabel *label2 = new QLabel("Member 1 41243214 何維禧");
    QLabel *label3 = new QLabel("Member 2 41243252 蔡承叡");
    QLabel *label4 = new QLabel("Member 3 41243120 林弘叡");

    layout1->addWidget(label1);
    layout1->addWidget(label2);
    layout1->addWidget(label3);
    layout1->addWidget(label4);
    tab1->setLayout(layout1);

    // Member 1 tab
    QWidget *tab2 = new QWidget();
    QVBoxLayout *layout2 = new QVBoxLayout();

    QPushButton *btn1 = new QPushButton("Change Text Color");

    layout2->addWidget(btn1);
    tab2->setLayout(layout2);

    QColorDialog *colorpicker = new QColorDialog;
    QObject::connect(btn1, &QPushButton::clicked, [=]() {
        colorpicker->open();
    });

    QObject::connect(colorpicker, &QColorDialog::colorSelected, [=](const QColor &color) {
        QString style = QString("color: %1;").arg(color.name());
        label1->setStyleSheet(style);
        label2->setStyleSheet(style);
        label3->setStyleSheet(style);
        label4->setStyleSheet(style);
    });

    // Member 2 tab with only a button
    QWidget *tab3 = new QWidget();
    QVBoxLayout *layout3 = new QVBoxLayout();
    QPushButton *member2Button = new QPushButton("Change Leader Text Style");

    QObject::connect(member2Button, &QPushButton::clicked, [=]() {
        bool ok;
        QFont font = QFontDialog::getFont(&ok, window);
        if (ok) {
            label1->setFont(font);
            label2->setFont(font);
            label3->setFont(font);
            label4->setFont(font);
        }
    });

    layout3->addWidget(member2Button);
    tab3->setLayout(layout3);

    // Member 3 tab with file selection functionality
    QWidget *tab4 = new QWidget();
    QVBoxLayout *layout4 = new QVBoxLayout();
    QPushButton *member3Button = new QPushButton("Select File");

    auto updateLabelsWithFilePath = [=](const QString &fileName) {
        if (!fileName.isEmpty()) {
            QString style = QString("%1").arg(fileName);
            label1->setText(style);
            label2->clear();
            label3->clear();
            label4->clear();
        }
    };

    QObject::connect(member3Button, &QPushButton::clicked, [=]() {
        QString fileName = QFileDialog::getOpenFileName(window, "Open a file", "", "All Files (*)");
        updateLabelsWithFilePath(fileName);
    });

    layout4->addWidget(member3Button);
    tab4->setLayout(layout4);

    tabWidget->addTab(tab1, "Leader");
    tabWidget->addTab(tab2, "Member 1");
    tabWidget->addTab(tab3, "Member 2");
    tabWidget->addTab(tab4, "Member 3");


    // Main window layout
    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addWidget(tabWidget);
    window->setLayout(mainLayout);

    window->resize(600, 300);
    window->show();

    return app.exec();
}
