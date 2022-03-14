1. Passagem de objetos sempre por referência

2. Observar a formatação do código

    if (...) {
    
    // ou
    
    if (...) 
    {

- Escolher um estilo e manter ele consistente em toda aplicação

3. Construtor deve sempre inicializar os atributos

        Cliente() {
        }

        Cliente() : _nome(""), _email(""), _data_nascimento(""), _idade(0) {}

4. Observar a indentação do código

5. Declarar um atributo por linha. Facilita visualizar todos os atributos e remover algum caso necessário. 

