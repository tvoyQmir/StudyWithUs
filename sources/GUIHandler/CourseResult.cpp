#include <QDebug>

#include "headers/GUIHandler/CourseResult.h"
#include "ui_CourseResult.h"
#include "headers/CustomTypes.h"
#include "headers/Facade.h"

CourseResult::CourseResult(QSharedPointer<Facade> facade, QWidget *parent)
    : QDialog(parent)
    , m_ui(new Ui::CourseResult)
    , m_Facade(facade)
{
    qDebug() << "GUIHandlerCourseResult::GUIHandlerCourseResult";
    m_ui->setupUi(this);

    QPixmap bkgnd(":/bkgnd/img/background/mainBackground.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

CourseResult::~CourseResult()
{
    qDebug() << "GUIHandlerCourseResult::~GUIHandlerCourseResult";
}

void CourseResult::updateData()
{
    const QVector<type::Result> results = m_Facade->getAllResults();
    m_ui->tableWidget->setRowCount(results.size());
    m_ui->tableWidget->setColumnCount(2);

    for(int row = 0; row < m_ui->tableWidget->rowCount(); ++row)
    {
      for(int column = 0; column < m_ui->tableWidget->columnCount(); column++)
      {
           QTableWidgetItem *item = new QTableWidgetItem();

           if (0 == column) // name
           {
               item->setText(results[row].studentName);
           }
           else if (1 == column) // progress
           {
               item->setText(QString::number(results[row].raiting));
           }

           m_ui->tableWidget->setItem(row, column, item);
      }
    }
}

void CourseResult::on_backToCourseMenu_clicked()
{
    qDebug() << "GUIHandlerCourseResult::on_backToCourseMenu_clicked";

    this->close();
    emit GUIHandlerCourseResultSignal();
}
