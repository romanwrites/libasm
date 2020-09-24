# libasm

## Research
<p>Little endian and big endian<br />
    <a href="https://agilescientific.com/blog/2017/3/31/little-endian-is-legal">
        <img style="background-color: white; width: 70vw;" src="https://images.squarespace-cdn.com/content/v1/549dcda5e4b0a47d0ae1db1e/1490746414666-EM74IA60AFM16OEH9G22/ke17ZwdGBToddI8pDm48kOMlUb6YZjvz-j7uj5wTIAtZw-zPPgdn4jUwVcJE1ZvWQUxwkmyExglNqGp0IvTJZamWLI2zvYWH8K3-s_4yszcp2ryTI0HqTOaaUohrI8PICROjhJFkM8GI5jSypQ9qrB6ZUKEpH8g8X8GW3p0wQZI/image-asset.png?format=1000w" alt="Little endian and big endian" href="https://agilescientific.com/blog/2017/3/31/little-endian-is-legal">
    </a>
</p>

<img src="img/assembler_intro_stolyarov1.png" style="width: 70vw;" alt="Скриншот книги Введение в программирование, Столяров." href="http://www.stolyarov.info/books/pdf/progintro_vol1.pdf">

[NASM Tutorial](https://cs.lmu.edu/~ray/notes/nasmtutorial/)

[x86_64 NASM Assembly Quick Reference ("Cheat Sheet")](https://www.cs.uaf.edu/2017/fall/cs301/reference/x86_64.html)

[strlen() implementation in NASM](https://tuttlem.github.io/2013/01/08/strlen-implementation-in-nasm.html)

[Difference between JE/JNE and JZ/JNZ](https://stackoverflow.com/questions/14267081/difference-between-je-jne-and-jz-jnz)

[Assembly - Conditions](https://www.tutorialspoint.com/assembly_programming/assembly_conditions.htm)

[Mac OS X 64 bit Assembly System Calls](http://dustin.schultz.io/mac-os-x-64-bit-assembly-system-calls.html)

### How to compile
```
nasm -f macho64 hello.s
ld -e start -macosx_version_min 10.13.0 -static -o hello hello.o
./hello
```

```
jmp     ; Unconditional Jump
je      ; Jump if Equal
jne     ; Jump if Not Equal
jg      ; Jump if Greater
jge     ; Jump if Greater or Equal
ja      ; Jump if Above (unsigned comparison)
jae     ; Jump if Above or Equal (unsigned comparison)
jl      ; Jump if Lesser
jle     ; Jump if Less or Equal
jb      ; Jump if Below (unsigned comparison)
jz      ; Jump if Zero
jnz     ; Jump if Not Zero
jc      ; Jump if carry set (C == 1)
jnc     ; Jump if carry is not set (C == 0)
```