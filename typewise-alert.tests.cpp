#include <gtest/gtest.h>
#include "typewise-alert.h"

extern BreachType Mock_classifyTemperatureBreach(CoolingType coolingType, double temperatureInC);
extern BreachType  mock_breach;
extern BreachType (*Func_ptr_classifyTemperatureBreach)(CoolingType, double);

TEST(TypeWiseAlertTestSuite,Test_check_and_alter_LOW_breach) {
Func_ptr_classifyTemperatureBreach = Mock_classifyTemperatureBreach;
BreachType expected_breach = TOO_LOW;
BatteryCharacter batteryChar = {PASSIVE_COOLING," "};
checkAndAlert(TO_CONTROLLER,batteryChar,-10);
EXPECT_EQ(mock_breach,expected_breach);

}

TEST(TypeWiseAlertTestSuite,Test_check_and_alter_High_breach) {
Func_ptr_classifyTemperatureBreach = Mock_classifyTemperatureBreach;
BreachType expected_breach = TOO_HIGH;
BatteryCharacter batteryChar = {PASSIVE_COOLING," "};
checkAndAlert(TO_CONTROLLER,batteryChar,50);
EXPECT_EQ(mock_breach,expected_breach);
}

TEST(TypeWiseAlertTestSuite,Test_check_and_alter_High_breach_Email) {
Func_ptr_classifyTemperatureBreach = Mock_classifyTemperatureBreach;
BreachType expected_breach = TOO_HIGH;
BatteryCharacter batteryChar = {HI_ACTIVE_COOLING," "};
checkAndAlert(TO_EMAIL,batteryChar,50);
EXPECT_EQ(mock_breach,expected_breach);
}


TEST(TypeWiseAlertTestSuite,Test_check_and_alter_Low_breach_Email) {
Func_ptr_classifyTemperatureBreach = Mock_classifyTemperatureBreach;
BreachType expected_breach = TOO_LOW;
BatteryCharacter batteryChar = {HI_ACTIVE_COOLING," "};
checkAndAlert(TO_EMAIL,batteryChar,-1);
EXPECT_EQ(mock_breach,expected_breach);
}

TEST(TypeWiseAlertTestSuite,Test_check_and_alter_Normal_breach) {
Func_ptr_classifyTemperatureBreach = Mock_classifyTemperatureBreach;
BreachType expected_breach = NORMAL;
BatteryCharacter batteryChar = {PASSIVE_COOLING," "};
checkAndAlert(TO_CONTROLLER,batteryChar,5);
EXPECT_EQ(mock_breach,expected_breach);
}

TEST(TypeWiseAlertTestSuite,Test_check_and_alter_boundary_condition) {
Func_ptr_classifyTemperatureBreach = Mock_classifyTemperatureBreach;
BreachType expected_breach = NORMAL;
BatteryCharacter batteryChar = {PASSIVE_COOLING," "};
checkAndAlert(TO_CONTROLLER,batteryChar,35);
EXPECT_EQ(mock_breach,expected_breach);
}
