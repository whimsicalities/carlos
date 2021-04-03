//Check the http_stuff for credits

#include <iostream>
#include "./http_stuff.h"
#include "python_ish.h"
#include <map>
using namespace std;
int main(void) {
  cout << "Server waking up...\n";
  httplib::Server svr;
  svr.Get("/", [](const auto &, auto &res) {
    cout << "get /";
    string head = "default"; //TODO: Customize
    string tail = "default"; //TODO: Customize
    string author = ""; //TODO: Customize
    string color = "#888888"; //TODO: Customize
    res.set_content("{\"apiversion\":\"1\", \"head\":\"" + head + "\", \"tail\":\"" + tail + "\", \"color\":\"" + color + "\"}", "text/json");
  });
  svr.Post("/move", [](auto &req, auto &res){
    cout << "Post /move";
    //get json data
    string data = req.body;
    cout << data;
    cout << "\n\n";
    string moves[4] = {"up", "down", "left", "right"};
    //TODO: Make some snake logic
    string move = "right";
    res.set_content("{\"move\": \"" + move + "\"}", "text/plain");
  });
  svr.Post("/end", [](const auto &, auto &res){
    cout << "Post /end";
    res.set_content("ok", "text/plain");
  });
  svr.Post("/start", [](const auto &, auto &res){
    cout << "Post /start";
    res.set_content("ok", "text/plain");
  });
  svr.listen("0.0.0.0", 8080);
}