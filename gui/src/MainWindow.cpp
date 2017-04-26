//
// MainWindow.cpp for Plazza in /home/gastal_r/rendu/Plazza/gui/src/
//
// Made by gastal_r
// Login   <remi.gastaldi@epitech.eu>
//
// Started on  Mon Apr 24 15:18:54 2017 gastal_r
// Last update Wed Apr 26 01:59:05 2017 gastal_r
//

#include      "MainWindow.hpp"
#include      <iostream>

MainWindow::MainWindow()
{
  setupUi(this);
  setWindowTitle("Plazza");
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
    for (size_t i = 0; i < it.getStatus().size(); ++i)
    {
      QListWidgetItem *listItem =  new QListWidgetItem(listWidget);
      //listItem->setIcon(QIcon("res/RedButton.png"));
      listItem->setText("File: " + QString(it.getOrders().at(i).first.c_str())
        + "\tInstruction: " +
        (it.getOrders().at(i).second == Information::EMAIL_ADDRESS ? "EMAIL_ADDRESS" :
          it.getOrders().at(i).second == Information::IP_ADDRESS ? "IP_ADDRESS" : "PHONE_NUMBER")
        + "\tStatus: " +
        (it.getStatus().at(i) == IThread::Status::NOT_STARTED ? "NOT_STARTED" :
          (it.getStatus().at(i) == IThread::Status::RUNNING ? "RUNNING" : "DEAD")));
      listWidget->addItem(listItem);
    }
  }
}
