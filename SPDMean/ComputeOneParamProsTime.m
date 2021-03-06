function [times, ComTime] = ComputeOneParamProsTime(As, alpha, x1, SolverParams, Xtrue)
    
    n = size(As{1}, 1);
    k = length(As);
    Ls = zeros(n, n, k);
    for i = 1 : k
        Ls(:, :, i) = As{i};
    end

    HasHHR = SolverParams.HasHHR;
    
    [Xopt, f, gf, gfgf0, iter, nf, ng, nR, nV, nVp, nH, ComTime, funs, grads, times] = TestSPDMeanLDOneParam(Ls, alpha, x1, HasHHR, SolverParams, Xtrue);

end
