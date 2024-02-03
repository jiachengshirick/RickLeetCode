struct Node {
    unordered_map<string, Node *> dir = {};
    vector <string> pathList = {};
    string content = "";
};

class FileSystem {
private:
    Node *main;
public:
    Node *file(string path) {
        Node *temp = main;
        stringstream ss(path);
        string nextPath;
        while (getline(ss, nextPath, '/')) {
            if (temp->dir[nextPath] == nullptr) {
                temp->pathList.push_back(nextPath);
                temp->dir[nextPath] = new Node;
            }
            temp = temp->dir[nextPath];
        }
        return temp;
    }

    FileSystem() {
        main = new Node();
    }

    vector <string> ls(string path) {
        Node *temp = file(path);
        if (temp->content.size())
            return {path.substr(path.find_last_of('/') + 1)};
        sort(temp->pathList.begin(), temp->pathList.end());
        return temp->pathList;
    }

    void mkdir(string path) {
        file(path);
    }

    void addContentToFile(string filePath, string content) {
        Node *temp = file(filePath);
        temp->content += content;
    }

    string readContentFromFile(string filePath) {
        Node *temp = file(filePath);
        return temp->content;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */