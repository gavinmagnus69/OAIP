#ifndef PARSE_H
#define PARSE_H
#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include <QStringList>
#include <QRegularExpressionMatchIterator>
#include <QStack>


QString searching_for_vars(const QString& mytext) {

    struct Token {
        QString type;
        QString name;
        QString default_value;
        int line;
    };

    std::vector<Token> tokens;
    std::regex variable_pattern(
            R"((?:(int|float|double|char|bool|short|long|string)\b\s+(([A-Za-z_][A-Za-z0-9_]*)(?:\s*=\s*([^,;]*))?\s*));)");

    int line_number = 0;
    int pos = 0;

    while (pos < mytext.size()) {
        int end_pos = mytext.indexOf('\n', pos);
        if (end_pos == -1) {
            end_pos = mytext.size();
        }

        QString line = mytext.mid(pos, end_pos - pos);
        line_number++;

        std::smatch matches;
        std::string std_line = line.toStdString();
        while (std::regex_search(std_line, matches, variable_pattern)) {
            tokens.push_back(Token{
                    QString::fromStdString(matches[1].str()),
                    QString::fromStdString(matches[3].str()),
                    QString::fromStdString(matches[4].str()),
                    line_number
            });
            std_line = matches.suffix().str();
        }

        pos = end_pos + 1;
    }

    QStringList output;
    for (const auto &token: tokens) {
        output << QString("Type: %1, Name: %2, Line: %3")
                .arg(token.type)
                .arg(token.name)
                .arg(token.line);
        if (!token.default_value.isEmpty()) {
            output.last().append(QString(", Default value: %1").arg(token.default_value));
        }
    }
    return output.join('\n');
}

QString serching_for_calsses(const QString& mytext) {
    int num_of_arrs = 0;
    int num_of_classes = 0;
    int num_of_structs = 0;

    QRegularExpression class_pattern(R"(class\s+\w+\s*\{)");
    QRegularExpression struct_pattern(R"(struct\s+\w+\s*\{)");
    QRegularExpression array_pattern(R"(\w+\s+\w+\s*\[\s*\d+\s*\](;|(\s*=\s*\{)?))");

    QRegularExpressionMatchIterator arr_itter = array_pattern.globalMatch(mytext);
    while (arr_itter.hasNext()) {
        arr_itter.next();
        ++num_of_arrs;
    }

    QRegularExpressionMatchIterator class_itter = class_pattern.globalMatch(mytext);
    while (class_itter.hasNext()) {
        class_itter.next();
        num_of_classes++;
    }

    QRegularExpressionMatchIterator struct_itter = struct_pattern.globalMatch(mytext);
    while (struct_itter.hasNext()) {
        struct_itter.next();
        num_of_structs++;
    }



    return QString(
            "Classes: " + QString::number(num_of_classes) +
            "\nStructures: " + QString::number(num_of_structs) +
            "\nArrays: " + QString::number(num_of_arrs)
    );
}

QString searching_for_funprots(const QString &code) {
    QString answer = "";
    QRegularExpression pattern(
            R"((int|float|double|char|bool|short|long|string|void)\s*(\*|\s)*\s*(\w+)\s*\((.*?)\)\s*(;|\{))");
    QRegularExpressionMatchIterator matches = pattern.globalMatch(code);

    while (matches.hasNext()) {
        QRegularExpressionMatch match = matches.next();
        QString capturedFunctionPrototype = match.captured(0);
        answer += capturedFunctionPrototype.mid(0, capturedFunctionPrototype.size() - 1) + "\n";
    }
    return answer;
}

QString searching_for_localvars(const QString &s) {
    QString answer = "";
    QStringList lines = s.split("\n");
    int br = 0;
    for (int i = 0; i < lines.size(); ++i) {
        if (std::count(lines[i].begin(), lines[i].end(), '{')) br++;
        if (br > 0) {
            std::regex pattern(
                    "\\b(?!(class|struct|void|return)\\s)(\\w+)((\\s+)|(\\s*(\\*)\\s*))(\\w+)\\s*(=\\s*(\\S+))?\\s*(,\\s*\\w+\\s*(=\\s*(\\S+))?)*\;");
            std::string c = lines[i].toStdString();
            std::cmatch match;
            while (std::regex_search(c.c_str(), match, pattern)) {
                answer += "line " + QString::number(i + 1) + " " + QString::fromStdString(match[0]) + "\n";
                c = match.suffix().first;
            }
        }
        if (std::count(lines[i].begin(), lines[i].end(), '}')) br--;
    }
    return answer;
}

QString searching_for_changes(const QString &s) {
    QStringList lines = s.split("\n");
    QString res;
    int line = 0;
    QRegularExpression pattern(R"((\b\w+\b)((\[[^\]]*\])*)\s*=\s*(.*);)");
    QRegularExpressionMatchIterator regexIterator = pattern.globalMatch(s);
    while (regexIterator.hasNext()) {
        QRegularExpressionMatch match = regexIterator.next();
        while (!lines[line].contains(match.captured(0)))
            line++;
        res += "Line " + QString::number(line) + ": " + match.captured() + "\n";
    }
    return res;
}

QString searching_for_redef_fun(const QString& mytext) {
    QString answer = "";
    QRegularExpression pattern(R"(\b([a-zA-Z_][a-zA-Z0-9_]*)\s+([a-zA-Z_][a-zA-Z0-9_]*)\s*\(([^()]*)\)\s*\{)");
    std::map<QString, QVector<int>> funs;
    int count = 0;
    QRegularExpressionMatchIterator regexIterator = pattern.globalMatch(mytext);

    while (regexIterator.hasNext()) {
        QRegularExpressionMatch match = regexIterator.next();
        QString functionName = match.captured(2);
        QString functionParameters = match.captured(3);
        int line = mytext.left(match.capturedStart()).count('\n');
        funs[functionName].push_back(line);
    }

    for (const auto &entry: funs) {
        if (entry.second.size() > 1) {
            answer += "Functions ";
            answer += entry.first;
            answer += " redefined in lines: ";
            for (auto line: entry.second) {
                answer += QString::number(line) + " ";
                count++;
            }
            answer += '\n';
        }
    }
    answer += "\n\nNumber of redefined functions " + QString::number(count);
    return answer;
}

QString search_for_depth(const QString& tmp) {
    QStringList lines = tmp.split("\n");
    QString answer = "";
    QRegularExpression pattern(R"(\b(if)\s*\(\S+.*\)\s*(\{?))");
    int b = 0;
    QStack<int> stack;

    for (int i = 0; i < lines.size(); i++) {
        QString line = lines[i];
        for (QChar ch: line) {
            if (ch == '{')
                b++;
            if (ch == '}') {
                if (!stack.empty() && stack.top() == b) {
                    stack.pop();
                }
                b--;
            }
        }
        QRegularExpressionMatchIterator regexIterator = pattern.globalMatch(line);
        while (regexIterator.hasNext()) {
            QRegularExpressionMatch match = regexIterator.next();
            if (match.captured(2) == "{") {
                stack.push(b);
                answer += QString::number(i + 1) + " : depth - " + QString::number(stack.size()) + "\n";
            } else {
                answer += QString::number(i + 1) + " : depth - " + QString::number(stack.size() + 1) + "\n";
            }
        }
    }
    return answer;
}

QString searching_for_errors(const QString &tmp) {
    QString mytext = tmp;
    QString answer;
    QRegularExpression expression(R"(((const)\s+(bool)\s+([a-z]*)\s*(=)\s*(true|false)\s*);)");
    QString b;
    QRegularExpressionMatch match;
    QRegularExpressionMatchIterator regexIterator = expression.globalMatch(mytext);

    while (regexIterator.hasNext()) {
        match = regexIterator.next();
        b = "while(";
        b += match.captured(4);
        b.push_back(')');

        QStringList lineList = tmp.split('\n');
        for (const auto &i: lineList) {
            if (b == i) {
                answer += match.captured(1);
                answer += '\n';
                answer += i;
                answer += '\n';
            }
        }
        mytext.remove(0, match.capturedEnd(0));
    }
    answer += '\n';
    QRegularExpression pattern(R"((while\(true\)|while\(false\)))");
    regexIterator = pattern.globalMatch(mytext);
    while (regexIterator.hasNext()) {
        match = regexIterator.next();
        answer += match.captured(0);
        answer += '\n';
        mytext.remove(0, match.capturedEnd(0));
    }
    if (answer == '\n') return "";
    return answer;
}
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}


void quicksort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quicksort(arr, low, pivot - 1);
        quicksort(arr, pivot + 1, high);
    }
}
QString boo(){
    //outpit
    std::vector<int> arr = { 5, 3, 8, 4, 2, 7, 1, 6 };
        quicksort(arr, 0, arr.size() - 1);
        ///
        ///
        QString bebebe = "sadsadasd";
        bebebe += "asdasda";
        return bebebe;
}
int binarySearch(const std::vector<int>& arr, int low, int high, int target) {
    if (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) {
            return binarySearch(arr, mid + 1, high, target);
        }
        else {
            return binarySearch(arr, low, mid - 1, target);
        }
    }
    return -1;
}
const int INF = INT_MAX;

struct Edge {
    int to;
    int weight;
    Edge(int to, int weight) : to(to), weight(weight) {}
};


void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::vector<int> leftArr(n1);
    std::vector<int> rightArr(n2);
    for (int i = 0; i < n1; ++i) {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; ++j) {
        rightArr[j] = arr[mid + 1 + j];
    }
    int i = 0;
    int j = 0;
    int k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            ++i;
        }
        else {
            arr[k] = rightArr[j];
            ++j;
        }
        ++k;
    }
    while (i < n1) {
        arr[k] = leftArr[i];
        ++i;
        ++k;
    }
    while (j < n2) {
        arr[k] = rightArr[j];
        ++j;
        ++k;
    }
}

void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

void dfs(TreeNode* node) {
    if (node == nullptr) {
        return;
    }
    std::cout << node->val << " ";
    dfs(node->left);
    dfs(node->right);
}
#endif // PARSE_H
