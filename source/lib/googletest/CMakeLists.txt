include(FetchContent)

FetchContent_Declare(googletest
  GIT_REPOSITORY  https://github.com/google/googletest.git
  GIT_TAG         release-1.11.0
  GIT_SHALLOW     ON
  GIT_PROGRESS    ON
)

FetchContent_MakeAvailable(googletest)
