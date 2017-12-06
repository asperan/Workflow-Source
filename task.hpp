#ifndef TASK_HPP
#define TASK_HPP

#include <cstdint>
#include <QString>
#include <vector>
#include <QGraphicsScene>
#include "childtext.hpp"

class Task
{

private:
  qint32 Id;
  QString Title;
  QString Text;
  std::vector<Task*> children;
  Task* Master;
  bool Completed;

public:

  explicit Task(Task* newMaster = Q_NULLPTR);
  explicit Task(qint32 newid, QString newTitle, QString newText, Task* newMaster);

  void setId(qint32 newId);
  qint32 getId();

  void setTitle(QString newTitle);
  QString getTitle();

  void setText(QString newText);
  QString getText();

  std::vector<Task*> getChildren();

  void setMaster(Task* newMaster);
  Task* getMaster();

  bool isCompleted();

  bool isCompletable();


  void setCompleted(bool isCompleted);
  Task *addChild(qint32 nextId, Task *newMaster);
  Task* addMaster(qint32 nextId);
  void addChild(Task* newChild);

  void drawAsChild(QGraphicsScene *childScene);
  void drawAsCurrent(QGraphicsScene* currentScene);

};

#include "taskwindow.hpp"


#endif // TASK_HPP