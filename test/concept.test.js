import WEBHMI from '../webhmi'

test('Import successful', ()=>{
    expect(WEBHMI).toBeDefined()
})

test('Variables defined', ()=>{
    expect(WEBHMI.Machine).toBeDefined()
    expect(typeof WEBHMI.version).toBe("string")
})