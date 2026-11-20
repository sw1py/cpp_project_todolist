#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

//Добавь в класс ToDoList штуку, для полученимя количества текущих задач
//Необходимо для вывода на экран и там вообще 
/*
Давайте придерживаться одного код стайла
В частности я пишу так:
if (sjjssj)
{
...
}

и вас прошу также, разный код стайл выглядит ужасно
еще между функциями и классами у меня по 2 отступа(ну как в дз по питону хаха)
между методами классов у меня 1 отступ
*/


class Record
{
public:
    Record(string record_name) : title(record_name) { };

    string get_title() const 
    { 
        return title; 
    };
    
    virtual ~Record() { };

    virtual bool is_task() const
    {
        return false;
    };

    virtual bool is_done() const
    {
        return false;
    };

    virtual void mark_done() { };

    virtual void mark_undone() { };

private:
    string title;
};


class Task : public Record
{
public:
    Task(string task_name) : Record(task_name), done(false) { };

    bool is_task() const override
    {
        return true;
    };

    bool is_done() const override
    { 
        return done; 
    };

    void mark_done() override
    { 
        done = true; 
    };

    void mark_undone() override
    { 
        done = false; 
    };

    // дедлайн и уведомления добавляет Эвелина

private:
    bool done;
};


class ToDoList 
{
public:
    ToDoList() { };

    ToDoList(const ToDoList&) = delete; // запрет создавать новый список как копию другого.
    ToDoList& operator=(const ToDoList&) = delete; // запрет перезаписывать существующий список копией другого.

    ~ToDoList()
    {
        clear();
    };

    void add_record(string record_name)
    {
        records.push_back(new Record {record_name});
    };

    void add_task(string task_name)
    {
        records.push_back(new Task {task_name});
    };

    int size() const
    {
        return records.size();
    };

    bool remove_record(int index)
    {
        if (!is_valid_index(index))
        {
            return false;
        }
        delete records[index];
        records.erase(records.begin() + index);
        return true;
    };

    string get_record_title(int index) const // Богданчик это для тебя
    {
        if (!is_valid_index(index))
        {
            return "";
        }
        return records[index]->get_title();
    };

    bool is_record_task(int index) const
    {
        if (!is_valid_index(index))
        {
            return false;
        }
        return records[index]->is_task();
    };

    bool is_record_done(int index) const
    {
        if (!is_valid_index(index))
        {
            return false;
        }
        return records[index]->is_done();
    };

    bool mark_record_done(int index)
    {
        if (!is_valid_index(index) || !records[index]->is_task())
        {
            return false;
        }
        records[index]->mark_done();
        return true;
    };

    bool mark_record_undone(int index)
    {
        if (!is_valid_index(index) || !records[index]->is_task())
        {
            return false;
        }
        records[index]->mark_undone();
        return true;
    };

    void print_records() const
    {
        for (int record_number {0}; record_number < size(); ++record_number)
        {
            cout << record_number + 1 << ". ";
            if (records[record_number]->is_task())
            {
                if (records[record_number]->is_done())
                {
                    cout << "[x] ";
                }
                else
                {
                    cout << "[ ] ";
                }
            }
            cout << records[record_number]->get_title() << endl;
        }
    };

    bool save_to_file(string filename) const
    {
        ofstream file {filename};
        if (!file)
        {
            return false;
        }
        for (int i {0}; i < size(); ++i)
        {
            if (records[i]->is_task())
            {
                file << 'T';
            }
            else
            {
                file << 'R';
            }
            file << ' ' << records[i]->is_done() << ' ' << records[i]->get_title() << endl;
        }
        return true;
    };

    bool load_from_file(string filename)
    {
        ifstream file {filename};
        if (!file)
        {
            return false;
        }
        clear();

        char type {' '};
        int done {0};
        string title;
        while (file >> type >> done && getline(file >> ws, title)) // произошел вайбкод
        {
            if (type == 'T')
            {
                Task* task {new Task {title}};
                if (done == 1)
                {
                    task->mark_done();
                }
                records.push_back(task);
            }
            else
            {
                records.push_back(new Record {title});
            }
        }
        return true;
    };

private:
    vector<Record*> records;

    void clear()
    {
        for (int i {0}; i < size(); ++i)
        {
            delete records[i];
        }
        records.clear();
    };

    bool is_valid_index(int index) const
    {
        return index >= 0 && index < size();
    };
};


//тесты3 5
// int main()
// {
//     ToDoList list;
//     list.add_record("Возможно надо сделать 67");
//     list.add_task("Сдать практикум");
//     list.add_record("Купить хлеб");
//     list.add_task("Написать бэкэнд");
//     list.mark_record_done(1);
//     if (!list.save_to_file("todo.txt"))
//     {
//         cout << "Не удалось сохранить файл" << endl;
//     }
//     ToDoList loaded;
//     if (!loaded.load_from_file("todo.txt"))
//     {
//         cout << "Не удалось открыть файл" << endl;
//     }
//     loaded.print_records();
// }
