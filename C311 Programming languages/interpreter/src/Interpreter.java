//      Hypothetical Machine Interpreter

public class Interpreter {

    static float Data[] = new float[100];
    static int Algorithm[] = new int[100];

    public static void main(String args[]) throws Exception
    {
        Load();
        Interpret();
    }

    static void Interpret()
    {
        int IP;
        boolean TraceOn = false;
        int  Instruction;
        int   Op;
        int   Opn1;
        int   Opn2;
        int   Dest;

        System.out.print("\tIP\tOp\tOpr1\tOpr2\tDest\n");
        IP = 0;

        while (true) {
// Fetch
            Instruction = Algorithm[IP];
// Decode
            Op = Instruction / 1000000;
            Dest = Math.abs(Instruction % 100);
            Opn2 = 0;
            Opn1 = 0;

            if (TraceOn)
                System.out.println("\t"+IP+"\t"+Op+"\t"+Opn1+"\t"+Opn2+"\t"+Dest);

// Update IP
            IP = IP + 1;

// Execute
            switch (Op) {
                case 0  : Data[Dest] = Data[Opn1]; break;
                case 1  : Data[Dest] = Data[Opn1] + Data[Opn2]; break;
                case 2  : Data[Dest] = Data[Opn1] * Data[Opn2]; break;
                case 3  : Data[Dest] = Data[Opn1] * Data[Opn1]; break;
                case 4  : if (Data[Opn1] == Data[Opn2]) IP = Dest; break;
                case 5  : if (Data[Opn1] >= Data[Opn2]) IP = Dest; break;
                case 6  : Data[Dest] = Data[Opn1 + (int)Data[Opn2]]; break;
                case 7  : Data[Opn1] = Data[Opn1] + 1;
                    if (Data[Opn1] < Data[Opn2]) IP = Dest; break;
                case 8  : Data[Dest] = C311.readFloat(); break;
                case 9  : return;
                case -1 : Data[Dest] = Data[Opn1] - Data[Opn2]; break;
                case -2 : Data[Dest] = Data[Opn1] / Data[Opn2]; break;
                case -3 : float x = Data[Opn1 + (int)Data[Opn2]];
                          float x1 = Data[Opn1 + (int)Data[Opn2]];
                          Data[Opn1 + (int)Data[Opn2]] = x1;
                          Data[Opn1 + (int)Data[Dest]] = x;
                          break;
                case -4 : if (Data[Opn1] != Data[Opn2]) IP = Dest; break;
                case -5 : if (Data[Opn1] <= Data[Opn2]) IP = Dest; break;
                case -6 : Data[Opn2 + (int)Data[Dest]] = Opn1; break;
                case -7 : break;
                case -8 :  System.out.println(Data[Opn1]); break;
                case -9 : TraceOn = !TraceOn;
            }
        }
    }

    static void Load()
    {
        int DataMemoryLocation;
        float DataValue;

        DataMemoryLocation = 0;
        while ((DataValue = C311.readFloat()) != 9999999.0){
            Data[ DataMemoryLocation ] = DataValue;
            DataMemoryLocation = DataMemoryLocation + 1;
        }

        int AlgorithmMemoryLocation;
        int Instruction;

        AlgorithmMemoryLocation = 0;
        while ((Instruction = C311.readInt()) != 9999999){
            Algorithm[ AlgorithmMemoryLocation ] = Instruction;
            AlgorithmMemoryLocation = AlgorithmMemoryLocation + 1;
        }
    }
}