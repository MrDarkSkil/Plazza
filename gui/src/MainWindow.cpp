//
// MainWindow.cpp for Plazza in /home/gastal_r/rendu/Plazza/gui/src/
//
// Made by gastal_r
// Login   <remi.gastaldi@epitech.eu>
//
// Started on  Mon Apr 24 15:18:54 2017 gastal_r
// Last update Fri Apr 28 11:34:13 2017 sellet_f
//

#include      "MainWindow.hpp"
#include      <iostream>

MainWindow::MainWindow(Plazza &plazza, Orders &order, char *av) : _plazza(plazza), _order(order), _av(av)
{
  setupUi(this);
  setWindowTitle("Plazza");
  QObject::connect(pushButton, SIGNAL(clicked()), this, SLOT(handleButton()));
}

void	MainWindow::handleButton(void)
{
  std::string line;

  line = lineEdit->text().toStdString();
  _order.clear();
  if (_order.parseLine(line) == -1)
    return ;
  _plazza.dividOrders(_order.getOrders(), std::stoi(_av), *this);
  lineEdit->clear();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
  event->accept();
}

void MainWindow::refreshList(const std::vector<NamedPipe::Data> &data)
{
  while (listWidget->count() > 0)
    listWidget->takeItem(0);

  for (auto & it : data)
  {
    QListWidgetItem *listItem =  new QListWidgetItem(listWidget);
    listItem->setText("PROCESS N°" + QString::number(it.getProcessId()));
    listWidget->addItem(listItem);
    for (size_t i = 0; i < it.getStatus().size(); ++i)
    {
      QListWidgetItem *listItem =  new QListWidgetItem(listWidget);
      if (it.getStatus().at(i) == IThread::Status::RUNNING)
        listItem->setIcon(QIcon("res/RedButton.png"));
      else
        listItem->setIcon(QIcon("res/GreenButton.png"));
      listItem->setText("File: " + (i < it.getOrders().size()
        ? QString(it.getOrders().at(i).first.c_str()) : "\t")
        + "\tInstruction: " + (i < it.getOrders().size() ?
        (it.getOrders().at(i).second == Information::EMAIL_ADDRESS ? "EMAIL_ADDRESS" :
          it.getOrders().at(i).second == Information::IP_ADDRESS ? "IP_ADDRESS" : "PHONE_NUMBER") : "\t\t")
        + "\tStatus: " +
        (it.getStatus().at(i) == IThread::Status::NOT_STARTED ? "NOT_STARTED" :
          (it.getStatus().at(i) == IThread::Status::RUNNING ? "RUNNING" : "DEAD")));
      listWidget->addItem(listItem);
    }
  }
}
