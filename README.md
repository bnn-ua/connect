# Prism Connect SDK

The Prism Connect SDK is a first class client library for the Prism Connect API. In addition to support for making all of the necessary network calls to the API, the SDK provides a standard suite of abstracted computer vision algorithms for interacting most effectively with the API. Finally, the SDK comes with a curated set of small example executables that can be used to build more complex applications, and they double as utilities for interacting with the API from the command line.

## Design

Simplicity, modularity, and flatness inform the design of the SDK. Here's how you query for all of the Prism accounts that can be accessed through a particular API token:

```c++
#include <iostream>

#include <api/client.h>
#include <api/environment.h>

int main() {
    prism::connect::api::Client client{prism::connect::api::environment::ApiRoot,
                                       prism::connect::api::environment::ApiToken};

    auto accounts = client.QueryAccounts();

    for (const auto& account : accounts) {
        std::cout << "Account[" << account.id_ << "]:" << std::endl;
        std::cout << "Name: " << account.name_ << std::endl;
        std::cout << "Url: " << account.url_ << std::endl;
        std::cout << "Instruments Url: " << account.instruments_url_ << std::endl;
        std::cout << std::endl;
    }

    return 0;
}
```

Similarly, performing background subtraction on a sequence of input images should be straightforward and fool-proof:

```c++
#include <iostream>

#include <opencv2/core.hpp>

#include <processors/background.h>

int main() {
    prism::connect::processors::Background background;

    cv::Mat input_image;

    while (true) {
        input_image = GetInputImageFromSomewhere(); // Function to populate a cv::Mat with image data
        background.AddImage(input_image);

        if (exit_loop) {
            break;
        }
    }

    cv::Mat background_image = background.GetBackgroundImage();
    cv::Mat foreground_mask = background.GetForegroundMask();

    return 0;
}
```
