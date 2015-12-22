/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/XmlPrinter.h>

int main( int argc, char *argv[] ) {
 int status;
    CxxTest::XmlPrinter tmp;
    CxxTest::RealWorldDescription::_worldName = "cxxtest";
    status = CxxTest::Main< CxxTest::XmlPrinter >( tmp, argc, argv );
    return status;
}
bool suite_TestDistanceAlgorithms_init = false;
#include "/home/noah/Documents/code/c++/TheBrain/vision/test/TestDistanceAlgorithms.h"

static TestDistanceAlgorithms suite_TestDistanceAlgorithms;

static CxxTest::List Tests_TestDistanceAlgorithms = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_TestDistanceAlgorithms( "TestDistanceAlgorithms.h", 5, "TestDistanceAlgorithms", suite_TestDistanceAlgorithms, Tests_TestDistanceAlgorithms );

static class TestDescription_suite_TestDistanceAlgorithms_testGetAngle : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDistanceAlgorithms_testGetAngle() : CxxTest::RealTestDescription( Tests_TestDistanceAlgorithms, suiteDescription_TestDistanceAlgorithms, 8, "testGetAngle" ) {}
 void runTest() { suite_TestDistanceAlgorithms.testGetAngle(); }
} testDescription_suite_TestDistanceAlgorithms_testGetAngle;

static class TestDescription_suite_TestDistanceAlgorithms_testGetDistanceToFinalRotation : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDistanceAlgorithms_testGetDistanceToFinalRotation() : CxxTest::RealTestDescription( Tests_TestDistanceAlgorithms, suiteDescription_TestDistanceAlgorithms, 12, "testGetDistanceToFinalRotation" ) {}
 void runTest() { suite_TestDistanceAlgorithms.testGetDistanceToFinalRotation(); }
} testDescription_suite_TestDistanceAlgorithms_testGetDistanceToFinalRotation;

static class TestDescription_suite_TestDistanceAlgorithms_testDistanceToTote : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDistanceAlgorithms_testDistanceToTote() : CxxTest::RealTestDescription( Tests_TestDistanceAlgorithms, suiteDescription_TestDistanceAlgorithms, 17, "testDistanceToTote" ) {}
 void runTest() { suite_TestDistanceAlgorithms.testDistanceToTote(); }
} testDescription_suite_TestDistanceAlgorithms_testDistanceToTote;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
