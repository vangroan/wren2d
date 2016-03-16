
foreign class FooBar {
    construct new() {}
    doScriptWork() {
        System.print("Doing script work")
    }
}

var fb = FooBar.new()

// [main line 31] Error at '}': Expected expression.
// [main line 33] Error at ')': Module variable is already defined.

