#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <numeric>

struct Mark {
    std::string subject_;
    size_t mark_;         
};

struct StudentData {
    std::string name_;          
    size_t number_;             
    std::vector<Mark> marks_;    

    double getAverageMark() const {
        if (marks_.empty()) return 0.0;
        double sum = 0;
        for (size_t i = 0; i < marks_.size(); ++i) {
            sum += marks_[i].mark_;
        }
        return sum / marks_.size();
    }
};

class StudentRegistry {
private:
    std::map<size_t, StudentData> students_; 

public:

    void loadFromFile(const std::string& filename) {
        std::ifstream file("students.txt");
        if (!file.is_open()) {
            std::cerr << "Ошибка: не удалось открыть файл " << filename << std::endl;
            return;
        }

        std::string line;
        while (std::getline(file, line)) {
            if (line.empty()) continue;
            std::stringstream ss(line);
            StudentData s;
            std::string temp;

            if (!std::getline(ss, temp, ';')) continue;
            s.number_ = std::stoul(temp);
            std::getline(ss, s.name_, ';');

            std::string m_block;
            while (std::getline(ss, m_block, ',')) {
                size_t colon = m_block.find(':');
                if (colon != std::string::npos) {
                    Mark m;
                    m.subject_ = m_block.substr(0, colon);
                    m.mark_ = std::stoul(m_block.substr(colon + 1));
                    s.marks_.push_back(m);
                }
            }
            students_[s.number_] = s;
        }
        file.close();
    }

    void printSortedById() const {
        std::cout << "\nСписок по номеру зачетки:\n";
        for (std::map<size_t, StudentData>::const_iterator it = students_.begin(); it != students_.end(); ++it) {
            std::cout << "№" << it->first << " | " << it->second.name_ << std::endl;
        }
    }

    void printAllAverages() const {
        std::cout << "\nСредний балл каждого студента:\n";
        for (std::map<size_t, StudentData>::const_iterator it = students_.begin(); it != students_.end(); ++it) {
            std::cout << it->second.name_ << ": " << std::fixed << std::setprecision(2)
                << it->second.getAverageMark() << std::endl;
        }
    }

    void printComplexSorted() const {
        std::vector<StudentData> vec;
        for (std::map<size_t, StudentData>::const_iterator it = students_.begin(); it != students_.end(); ++it) {
            vec.push_back(it->second);
        }

        std::sort(vec.begin(), vec.end(), [](const StudentData& a, const StudentData& b) {
            if (a.name_ != b.name_) return a.name_ < b.name_;
            return a.getAverageMark() > b.getAverageMark();
            });

        std::cout << "\nСписок студентов:\n";
        for (size_t i = 0; i < vec.size(); ++i) {
            std::cout << (i + 1) << ". " << std::setw(15) << vec[i].name_
                << " | Зачетка: " << vec[i].number_
                << " | Ср. балл: " << std::fixed << std::setprecision(2) << vec[i].getAverageMark() << "\n";
        }
    }

    void printInRange(double min_val, double max_val) const {
        std::vector<StudentData> vec;
        for (std::map<size_t, StudentData>::const_iterator it = students_.begin(); it != students_.end(); ++it) {
            double avg = it->second.getAverageMark();
            if (avg >= min_val && avg <= max_val) vec.push_back(it->second);
        }

        std::sort(vec.begin(), vec.end(), [](const StudentData& a, const StudentData& b) {
            return a.getAverageMark() > b.getAverageMark();
            });

        std::cout << "\nСтуденты с баллом от " << min_val << " до " << max_val << ":\n";
        for (size_t i = 0; i < vec.size(); ++i) {
            std::cout << vec[i].name_ << " (Балл: " << vec[i].getAverageMark() << ")\n";
        }
    }

    void printBySubject(const std::string& subjectName) const {
        std::cout << "\nСтуденты, сдавшие предмет '" << subjectName << "':\n";
        for (std::map<size_t, StudentData>::const_iterator it = students_.begin(); it != students_.end(); ++it) {
            for (size_t i = 0; i < it->second.marks_.size(); ++i) {
                if (it->second.marks_[i].subject_ == subjectName) {
                    std::cout << it->second.name_ << std::endl;
                    break;
                }
            }
        }
    }

    void printSubjectCounts() const {
        std::map<std::string, int> counts;
        for (std::map<size_t, StudentData>::const_iterator it = students_.begin(); it != students_.end(); ++it) {
            for (size_t i = 0; i < it->second.marks_.size(); ++i) {
                counts[it->second.marks_[i].subject_]++;
            }
        }
        std::cout << "\nКоличество сдавших по предметам:\n";
        for (std::map<std::string, int>::iterator it = counts.begin(); it != counts.end(); ++it) {
            std::cout << it->first << ": " << it->second << " чел.\n";
        }
    }

    void printSubjectAverages() const {
        std::map<std::string, std::vector<size_t>> sub_marks;
        for (std::map<size_t, StudentData>::const_iterator it = students_.begin(); it != students_.end(); ++it) {
            for (size_t i = 0; i < it->second.marks_.size(); ++i) {
                sub_marks[it->second.marks_[i].subject_].push_back(it->second.marks_[i].mark_);
            }
        }

        std::vector<std::pair<std::string, double>> result;
        for (std::map<std::string, std::vector<size_t>>::iterator it = sub_marks.begin(); it != sub_marks.end(); ++it) {
            double sum = 0;
            for (size_t i = 0; i < it->second.size(); ++i) sum += it->second[i];
            result.push_back(std::make_pair(it->first, sum / it->second.size()));
        }

        std::sort(result.begin(), result.end(), [](const std::pair<std::string, double>& a, const std::pair<std::string, double>& b) {
            return a.second > b.second;
            });

        std::cout << "\nСредний балл по предметам:\n";
        for (size_t i = 0; i < result.size(); ++i) {
            std::cout << result[i].first << ": " << std::fixed << std::setprecision(2) << result[i].second << std::endl;
        }
    }

    void printMaxTotal() const {
        size_t global_max = 0;
        for (std::map<size_t, StudentData>::const_iterator it = students_.begin(); it != students_.end(); ++it) {
            size_t current_sum = 0;
            for (size_t i = 0; i < it->second.marks_.size(); ++i) current_sum += it->second.marks_[i].mark_;
            if (current_sum > global_max) global_max = current_sum;
        }

        std::cout << "\nСтуденты с макс. суммой баллов (" << global_max << "):\n";
        for (std::map<size_t, StudentData>::const_iterator it = students_.begin(); it != students_.end(); ++it) {
            size_t current_sum = 0;
            for (size_t i = 0; i < it->second.marks_.size(); ++i) current_sum += it->second.marks_[i].mark_;
            if (current_sum == global_max) std::cout << it->second.name_ << std::endl;
        }
    }

    void printDebtors() const {
        std::cout << "\n[Студенты с оценками 1, 2 или 3:\n";
        for (std::map<size_t, StudentData>::const_iterator it = students_.begin(); it != students_.end(); ++it) {
            bool bad = false;
            for (size_t i = 0; i < it->second.marks_.size(); ++i) {
                if (it->second.marks_[i].mark_ <= 3) {
                    bad = true;
                    break;
                }
            }
            if (bad) std::cout << it->second.name_ << " (Зачетка: " << it->first << ")\n";
        }
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    StudentRegistry registry;

    registry.loadFromFile("data.txt");

    registry.printSortedById();      // задание 2
    registry.printAllAverages();     // задание 3
    registry.printComplexSorted();   // задание 4
    registry.printInRange(4.0, 5.0); // задание 5
    registry.printBySubject("Физика"); // задание 6
    registry.printSubjectCounts();   // задание 7
    registry.printSubjectAverages(); // задание 8
    registry.printMaxTotal();        // задание 9
    registry.printDebtors();         // задание 10

    return 0;
}
