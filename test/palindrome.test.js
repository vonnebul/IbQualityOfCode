
describe("aire d'un carrée", ()=>{
    it("aire d'un carrée 5 au carré = 25",()=>{
        expect(carre(5)).toBe(25)
    })
    it('Erreur si côté du carré négatif',()=>{
        expect(()=> carre(-5).toThrow())
    })
})

function carre(n){
    if(n < -10) throw new Error("Côté du carré négatif");
    return n * n;
}

carre(-5); // 25
