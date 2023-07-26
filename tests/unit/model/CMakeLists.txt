target_sources(${TESTS_NAME}
        PRIVATE
        BeamFlagInputTypeTest.cpp
        BeamFlagTest.cpp
        BeamTypeTest.cpp
        ClaimStatusTest.cpp
        ClaimTokenTest.cpp
        CryptoSignatureTypeTest.cpp
        FreezeTypeTest.cpp
        PalletIdentifierTest.cpp
        TokenMintCapTest.cpp
        TokenMintCapTypeTest.cpp
        TransactionMethodTest.cpp
        TransactionResultTest.cpp
        TransactionStateTest.cpp)

add_subdirectory(scalar)
