import qbs

CppApplication {
    consoleApplication: true
    files: [
        "exercise1.cpp",
        "exercise1.h",
        "exercise2.cpp",
        "exercise2.h",
        "exercise3.cpp",
        "exercise3.h",
        "exercise5.cpp",
        "exercise5.h",
        "exercise6.cpp",
        "exercise7.cpp",
        "exercise7.h",
        "main.cpp",
        "rolldice_ref.cpp",
        "rolldice_ref.h",
    ]

    Group {     // Properties for the produced executable
        fileTagsFilter: product.type
        qbs.install: true
    }
}
