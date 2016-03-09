
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