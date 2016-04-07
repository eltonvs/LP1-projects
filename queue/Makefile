### Programas
CXX = g++
DELETAR = /bin/rm

### Variáveis
#DEPURA = -ggdb
AVISA = -Wall
#PROFILA = -pg
#OTIMIZA = -O2
PADRAO_LINGUAGEM = c++11  #c++0x  # c++98
BIBLIOTECA_PADRAO = libc++
#BIBLIOTECAS = -lm


### Diretórios
#DIRBIBLIOTECAS = -L/opt/local/lib
DIREXECUTAVEL = bin
DIRFONTE = src
DIRINCLUDE = include
DIRDECLARACOES = -I. -I $(DIRINCLUDE) -I $(DIRFONTE)

### Flags de compilação
CFLAGS = $(AVISA) $(DEPURA)$ $(PROFILA) $(OTIMIZA) -std=$(PADRAO_LINGUAGEM)

### Flags de linkedição
LFLAGS = $(AVISA) $(DIRBIBLIOTECAS) $(BIBLIOTECAS) #-stdlib=$(BIBLIOTECA_PADRAO)

### Dependências
OBJS = $(DIREXECUTAVEL)/drive_queue.o # outras ...

### Entradas
# a primeira entrada eh para o programa alvo
arraylist: $(OBJS)
	@echo ">>> Gerando executavel."
	$(CXX) $(LFLAGS) $(OBJS) -o $(DIREXECUTAVEL)/drive_queue

# essa entrada define como produzir o arquivo
#Classe_LLSeq.o: Classe_LLSeq.cpp Classe_LLSeq.h
$(DIREXECUTAVEL)/drive_queue.o: $(DIRFONTE)/drive_queue.cpp $(DIRINCLUDE)/queue.h $(DIRINCLUDE)/queue.inl
	@echo ">>> Compilando dependencias."
	$(CXX) $(CFLAGS) $(DIRDECLARACOES) -c $(DIRFONTE)/drive_queue.cpp  \
	    -o $(DIREXECUTAVEL)/drive_queue.o

$(DIRINCLUDE)/queue.h: $(DIRINCLUDE)/queue.inl

# a entrada seguinte elimina os arquivos inuteis.
clean:
	@echo ">>> Limpando projeto."
	$(DELETAR) $(DIREXECUTAVEL)/*.o $(DIRFONTE)/*~ \
	   $(DIRINCLUDE)/*~ $(DIREXECUTAVEL)/drive_queue
