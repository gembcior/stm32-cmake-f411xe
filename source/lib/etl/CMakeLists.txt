include(FetchContent)

FetchContent_Declare(etl
  GIT_REPOSITORY  https://github.com/ETLCPP/etl.git
  GIT_TAG         20.11.4
  GIT_SHALLOW     ON
  GIT_PROGRESS    ON
)

FetchContent_MakeAvailable(etl)
