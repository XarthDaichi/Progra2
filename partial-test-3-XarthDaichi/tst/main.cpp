//
// Created by Maikol Guzman Alan on 5/18/22.
//

#define CATCH_CONFIG_RUNNER
#include "../lib/catch2/catch.hpp"

int main( int argc, char* argv[] ) {
    // global setup...

    int result = Catch::Session().run( argc, argv );

    // global clean-up...

    return result;
}