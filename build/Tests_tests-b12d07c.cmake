add_test( [==[Boot performance]==] /Users/davidrichter/prog/personal/audio/juce-projects/fm-four/build/Tests [==[Boot performance]==]  )
set_tests_properties( [==[Boot performance]==] PROPERTIES WORKING_DIRECTORY /Users/davidrichter/prog/personal/audio/juce-projects/fm-four/build)
add_test( [==[one is equal to one]==] /Users/davidrichter/prog/personal/audio/juce-projects/fm-four/build/Tests [==[one is equal to one]==]  )
set_tests_properties( [==[one is equal to one]==] PROPERTIES WORKING_DIRECTORY /Users/davidrichter/prog/personal/audio/juce-projects/fm-four/build)
add_test( [==[Plugin instance name]==] /Users/davidrichter/prog/personal/audio/juce-projects/fm-four/build/Tests [==[Plugin instance name]==]  )
set_tests_properties( [==[Plugin instance name]==] PROPERTIES WORKING_DIRECTORY /Users/davidrichter/prog/personal/audio/juce-projects/fm-four/build)
set( Tests_TESTS [==[Boot performance]==] [==[one is equal to one]==] [==[Plugin instance name]==])
