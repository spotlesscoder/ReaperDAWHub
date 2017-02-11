# Building

1. Install Reaper x64 to default location (set REAPER64_DIR environment variable to this path)
2. Install Reaper x86 to default location (set REAPER_DIR environment variable to this path)


Install VS 2015 Community Edition

Checkout repository

Install JUCE library version 4.3.1 to <your_checkout_path>/..

It should look somehow like this:

+Projects
  -JUCE
   -doxygen
   -examples
   -extras
   -modules
  -ReaperDAWHub

Run VS2015 as administrator (because build output is directly written to Reaper program dir)

Open ReaperDAWHub.sln

Contribute
