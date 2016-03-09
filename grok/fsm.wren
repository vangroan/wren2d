

class Fsm {
    construct new() {
	_states = {}
	_current = null
    }
    
    current { _current }
    
    changeState(newState) {
	if (_current) _current.onExit()
	_current = newState
	if (_current) _current.onEnter()
    }
    
    setState(key, state) {
	_states[key] = state
    }
    
    getState(key) {
	return _states[key]
    }
    
    switch(key) {
	var state = getState(key)
	changeState(state)
    }
}


// =====
// Tests
// =====

class WalkState {
    construct new() {}
    
    onEnter() { System.print("Walk Enter") }
    
    onExit() { System.print("Walk Exit") }
}


class IdleState {
    construct new() {}
    
    onEnter() { System.print("Idle Enter") }
    
    onExit() { System.print("Idle Exit") }
}


class FsmTests {
    static test_setState() {
	var fsm = Fsm.new()
	fsm.setState("test", WalkState.new())
	this.assert(fsm.getState("test"), "State 'test' not found")
    }
    
    static test_switch() {
	var fsm = Fsm.new()
	var walk = WalkState.new()
	fsm.setState("walk", walk)
	fsm.switch("walk")
	this.assert(fsm.current == walk, "State did not switch to walk")
    }
    
    static test_switch2() {
	var fsm = Fsm.new()
	var walk = WalkState.new()
	var idle = IdleState.new()
	fsm.setState("walk", walk)
	fsm.setState("idle", idle)
	fsm.switch("walk")
	fsm.switch("idle")
	this.assert(fsm.current == idle, "State did not switch from walk to idle")
    }
    
    static assert(t, msg) {
	if (!t) System.print("[Error] %(msg)") else System.print("Test passed")
    }
}

FsmTests.test_setState()
FsmTests.test_switch()
FsmTests.test_switch2()