#include <iostream>
#include <io.h>
#include <fcntl.h>

#include "net/ApiClient.hpp"
#include "data/User.hpp"
#include "MainWindow.hpp"

int main() {
    /*MainWindow::init("RollAndPlay - Game System", "../../config.json");

    auto window = MainWindow::getInstance();

    window->setClearColor(glm::vec4{0.2f});

    window->run();

    MainWindow::free();*/

    Net::ApiClient client("localhost", "8080");

    Data::User user;
    user.setPassword(u"pass10202");
    user.setEmail(u"user@example0.org");

    Json::Value body;
    user.serialize(body);

    Json::StyledWriter styledWriter;
    std::string json = styledWriter.write(body);
    std::cout << json << std::endl;

    Net::HttpRequest request("/users", Net::Http::MethodPost, "localhost:8080");
    request.setBodyJson(body);

    auto response = client.connect(request);

    Data::User testUser;
    auto responseBody = response.getBody();
    testUser.deserialize(responseBody);

    std::cout << 0 << std::endl;

    return 0;
}
