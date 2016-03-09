
System.print("Hello World")

class Graphics {
    construct new() {}
    draw() {
        System.print("Do some drawing")
    }
}

var g = Graphics.new()
g.draw()

class MyClass {
    foreign static add(a, b)
    foreign static sub(a, b)
}

System.print("Add: %(MyClass.add(7, 11))")
System.print("Add: %(MyClass.add(7, 11))")
System.print("Sub: %(MyClass.sub(7, 11))")

foreign class FooBar {
    doScriptWork() {
        System.print("Doing script work")
    }
}

var fb = FooBar.new()

// [main line 31] Error at '}': Expected expression.
// [main line 33] Error at ')': Module variable is already defined.

