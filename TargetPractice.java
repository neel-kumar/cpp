import java.io.*;
import java.util.*;

public class TargetPractice {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int nloc = sc.nextInt();
        int ncommands = sc.nextInt();
        boolean[] locations = new boolean[2*ncommands+5];
        for (int i = 0; i < nloc; i++){
            locations[sc.nextInt()+ncommands] = true;
        }
        String command = sc.next();
        HashMap<Integer, Integer> currentHit = new HashMap<>();
        HashMap<Integer,Integer> whenHit = new HashMap<>();
        int cur_pos = ncommands;
        for (int i = 0; i < ncommands; i++){
            if (command.charAt(i) == 'F'){
                if (locations[cur_pos] && !currentHit.containsKey(cur_pos)){
                    currentHit.put(cur_pos, i);
                    whenHit.put(i,cur_pos);
                }
            }
            cur_pos += (command.charAt(i) == 'L') ? -1 : 0;
            cur_pos += (command.charAt(i) == 'R') ? 1 : 0;
        }
        int max = currentHit.size();
        HashSet[] rightSide = new HashSet[5];
        for (int i = 0; i < 5; i++) rightSide[i] = new HashSet<Integer>();
        HashSet[] toBeAdded = new HashSet[5];
        for (int i = 0; i < 5; i++) toBeAdded[i] = new HashSet<Integer>();
        for (int i = ncommands-1; i >= 0; i--){
            if (whenHit.containsKey(i)){
                currentHit.remove(whenHit.get(i));
                whenHit.remove(i);
                for (int j = 0; j < 5; j++){
                    if (toBeAdded[j].contains(cur_pos)){
                        rightSide[j].add(cur_pos);
                        toBeAdded[j].remove(cur_pos);
                    }
                }
            }
            cur_pos += (command.charAt(i) == 'L') ? 1 : 0;
            cur_pos += (command.charAt(i) == 'R') ? -1 : 0;
            switch (command.charAt(i)){
                case 'L':
                    // try F and add all displacement 1
                    int addL = locations[cur_pos] && !currentHit.containsKey(cur_pos) && !rightSide[3].contains(cur_pos)? 1 : 0;
                    max = Math.max(max, whenHit.size()+addL+rightSide[3].size());
                    // try changing to R
                    max = Math.max(max, whenHit.size()+rightSide[4].size());
                    break;
                case 'R':
                    // try F and add all displacement 1
                    int addR = locations[cur_pos] && !currentHit.containsKey(cur_pos) && !rightSide[1].contains(cur_pos) ? 1 : 0;
                    max = Math.max(max, whenHit.size()+addR+rightSide[1].size());
                    // try changing to L
                    max = Math.max(max, whenHit.size()+rightSide[0].size());
                     break;
                case 'F':
                    // Try changing to L
                    max = Math.max(max, whenHit.size()+rightSide[1].size());
                    // Try changing to R
                    max = Math.max(max, whenHit.size()+rightSide[3].size());
                    break;
            }
            if (command.charAt(i) == 'F') {
                for (int j = cur_pos - 2; j <= cur_pos + 2; j++) {
                    if (j < 0 || j >= locations.length) continue;
                    if (locations[j]){
                        if (currentHit.containsKey(j)) {
                            toBeAdded[j - cur_pos + 2].add(j);
                        }else{
                            rightSide[j-cur_pos+2].add(j);
                        }
                    }
                }
            }

        }
        System.out.println(max);

    }
}
