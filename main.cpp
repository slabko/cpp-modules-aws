#include <iostream>
#include <aws/core/Aws.h>
#include <aws/core/utils/logging/LogLevel.h>
#include <aws/s3/S3Client.h>

int main() {
  std::cout << "starting" << std::endl;

  Aws::SDKOptions options;
  options.loggingOptions.logLevel = Aws::Utils::Logging::LogLevel::Debug;

  Aws::InitAPI(options);

  {
    Aws::S3::S3Client client;
    auto outcome = client.ListBuckets();

    if (outcome.IsSuccess()) {
      std::cout << "Found " << outcome.GetResult().GetBuckets().size() << " buckets" << std::endl;

      for (auto &&b : outcome.GetResult().GetBuckets()) {
        std::cout << b.GetName() << std::endl;
      }
    }
    else {
      std::cout << "Failed with error: " << outcome.GetError() << std::endl;
    }
  }

  Aws::ShutdownAPI(options);

  return 0;
}
