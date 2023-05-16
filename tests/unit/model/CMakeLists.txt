target_sources(${TESTS_NAME}
        PRIVATE
        PalletIdentifierTest.cpp
        TokenMintCapTypeTest.cpp
        TransactionMethodTest.cpp
        TransactionResultTest.cpp
        TransactionStateTest.cpp)

add_subdirectory(scalar)
