import LUX from '../lux'

test('Import successful', ()=>{
    expect(LUX).toBeDefined()
})

test('Variables defined', ()=>{
    expect(LUX.Machine).toBeDefined()
    expect(typeof LUX.version).toBe("string")
})