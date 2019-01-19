package info.lofei.demo.jvmti;

import com.sun.tools.attach.AgentInitializationException;
import com.sun.tools.attach.AgentLoadException;
import com.sun.tools.attach.AttachNotSupportedException;
import com.sun.tools.attach.VirtualMachine;

import java.io.IOException;
import java.util.Arrays;

public class VMAttacher {

    public static void main(String[] args) {
//        VirtualMachine.list().forEach(System.out::println);
        Arrays.stream(args).forEach(System.out::println);
        VirtualMachine.list().forEach(virtualMachineDescriptor -> {
            if ("info.lofei.demo.jvmti.Main".equals(virtualMachineDescriptor.displayName())) {
                try {
                    VirtualMachine virtualMachine = VirtualMachine.attach(virtualMachineDescriptor.id());
                    // args[0]为共享库路径，args[1]为传递给agent的参数
                    if (args.length >= 2) {
                        virtualMachine.loadAgentPath(args[0], args[1]);
                    } else {
                        virtualMachine.loadAgentPath(args[0]);
                    }
                    virtualMachine.detach();
                } catch (IOException | AgentLoadException | AgentInitializationException | AttachNotSupportedException e) {
                    e.printStackTrace();
                }
            }
        });

    }
}