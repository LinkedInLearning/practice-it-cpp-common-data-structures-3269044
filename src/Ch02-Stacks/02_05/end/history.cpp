#include <iostream>
#include <stack>
#include <string>

using namespace std;

class BrowserHistory
{
private:
    stack<string> history;

public:
    // Visiting a website
    void visit(const string &url)
    {
        cout << "Visiting: " << url << endl;
        history.push(url);
    }

    // Clicking the back button
    void back()
    {
        cout << "Navigating back" << endl;
        if (!history.empty())
        {
            history.pop();
        }
    }

    // Checking the current site
    string current() const
    {
        if (history.empty())
        {
            return "No sites currently being viewed.";
        }
        return history.top();
    }
};

int main()
{
    BrowserHistory bh;

    bh.visit("explorecalifornia.org");
    bh.visit("pixelford.com");
    bh.visit("landonhotel.com");

    cout << "Current Site: " << bh.current() << endl;

    bh.back();
    cout << "Current Site: " << bh.current() << endl;

    bh.back();
    cout << "Current Site: " << bh.current() << endl;

    bh.back();
    cout << "Current Site: " << bh.current() << endl;

    return 0;
}
