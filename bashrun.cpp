#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

void replace_all(string &str, const string &from, const string &to) {
    string::size_type pos(0);
    while (true) {
        if ((pos = str.find(from)) != string::npos)
            str.replace(pos, from.length(), to);
        else
            break;
    }
}

void wsl_path(string &win_path) {
    win_path[0] = tolower(win_path[0]);
    replace_all(win_path, ":", "");
    replace_all(win_path, "\\", "/");
    win_path = "/mnt/" + win_path;
}

void split_name(const string &filename, string &basename, string &extname) {
    string::size_type p, i;
    for (i = 0; i < filename.size(); i++)
        if (filename[i] == '.')
            p = i;
    basename = filename.substr(0, p);
    extname = filename.substr(p);
}

int main(int argc, char **argv) {
    if (argc == 2) {
        string filename(argv[1]);
        wsl_path(filename);
        string basename;
        string extname;
        split_name(filename, basename, extname);
        string cmd(getenv("WINDIR"));
        cmd += "\\Sysnative\\bash.exe -c ";
        if (extname == ".c")
            cmd += "\"gcc -std=c99 -Wall '" + filename + "' -o '" + basename +
                   ".out' && '" + basename + ".out'\"";
        else if (extname == ".cpp")
            cmd += "\"g++ -std=c++11 -Wall '" + filename + "' -o '" + basename +
                   ".out' && '" + basename + ".out'\"";
        else if (extname == ".java")
            cmd += "\"javac '" + filename + "' && java '" + basename + "'";
        else if (extname == ".py")
            cmd += "\"python3 '" + filename + "'";
        else
            cmd = "echo Unsupported File Type";
        system(cmd.c_str());
    } else {
        cout << "bashrun <file_path>\n";
        cout << "\tfile_path:\tcode file path, e.g. C:\\Project1\\main.cpp\n";
    }
    system("pause");
    return 0;
}